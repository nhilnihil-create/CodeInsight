#include <iostream>
#include <cmath>

int main() {
    unsigned long x;
    std:: cin >> x;

    for (int i = -150; i <= 150; ++i) {
        for (int j = -150; j <= 150; ++j) {
            unsigned long pow1 = std::pow(i, 5);
            unsigned long pow2 = std::pow(j, 5);
            if (pow1 - pow2 == x || pow2 - pow1 == x ) {
                std::cout << std::max(i, j) << " " << std::min(i, j);
                return 0;
            }
        }
    }
}