#include <iostream>

int n, r;

int main() {
    std::cin >> n >> r;
    if (n < 10) {
        std::cout << r + (100 * (10 - n));
    } else {
        std::cout << r;
    }
}