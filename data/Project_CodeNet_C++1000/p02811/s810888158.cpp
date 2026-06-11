#include <iostream>

int main(void) {
    int k, x;
    std::cin >> k >> x;
    if (500 * k >= x) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}