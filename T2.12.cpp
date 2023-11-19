#include <iostream>
#include <string>
#include <type_traits>

// Define a struct for Cat
struct Cat {
    std::string masterName;
    int age;
};

// Define a struct for Person
struct Person {
    std::string name;
    int age;
};

// Function to find the variable with the minimum age (same type)
template <typename T>
T findMinAge(const T& a, const T& b) {
    return (a.age < b.age) ? a : b;
}

// Function to find the variable with the minimum age (different types)
template <typename T1, typename T2>
auto findMinAge(const T1& a, const T2& b) -> decltype((a.age < b.age) ? a : b) {
    return (a.age < b.age) ? a : b;
}

// Function to check if variables have the same age (same type)
template <typename T>
bool haveSameAge(const T& a, const T& b) {
    return (a.age == b.age);
}

// Function to check if variables have the same age (different types)
template <typename T1, typename T2>
bool haveSameAge(const T1& a, const T2& b) {
    return (a.age == b.age);
}

int main() {
    // Example with variables of the same type (Cat)
    Cat cat1 = { "John", 5 };
    Cat cat2 = { "Alice", 3 };

    Cat minAgeCat = findMinAge(cat1, cat2);
    bool sameAgeCats = haveSameAge(cat1, cat2);

    std::cout << "Cat with minimum age: " << minAgeCat.masterName << " (Age: " << minAgeCat.age << ")\n";
    std::cout << "Do cats have the same age? " << (sameAgeCats ? "Yes" : "No") << "\n\n";

    // Example with variables of different types (Cat and Person)
    Person person = { "Bob", 4 };

    auto minAge = findMinAge(cat1, person);
    bool sameAge = haveSameAge(cat1, person);

    std::cout << "Variable with minimum age: ";
    if constexpr (std::is_same_v<decltype(minAge), Cat>) {
        std::cout << "Cat " << minAge.masterName << " (Age: " << minAge.age << ")\n";
    }
    else {
        std::cout << "Person " << person.name << " (Age: " << person.age << ")\n";
    }

    std::cout << "Do variables have the same age? " << (sameAge ? "Yes" : "No") << "\n";

    return 0;
}
