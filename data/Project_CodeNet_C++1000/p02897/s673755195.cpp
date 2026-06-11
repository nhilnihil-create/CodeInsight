#include <iostream>

int n;

int main() {
    std::cin >> n;
    int even;
    even = n / 2;
    std::cout << (n - even + 0.0) / n;
}