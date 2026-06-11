#include <iostream>
#include <string>

std::string s;
char first;
char second;
char third;
char forth;

int main() {
    std::cin >> s;

    first = s.at(0);
    second = s.at(1);
    third = s.at(2);
    forth = s.at(3);

    if (
        ((first == second) && (third==forth) && (first != third)) ||
        ((first == third) && (second==forth) && (first != second)) ||
        ((first == forth) && (third==second) && (first != second))
    ) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }

    return 0;
}