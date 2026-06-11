#include <iostream>
int main() {
    int x, y;
    for (std::cin >> x >> y; x != 0 || y != 0; std::cin >> x >> y) {
        if (x < y) {
            std::cout << x << ' ' << y << std::endl;
        } else {
            std::cout << y << ' ' << x << std::endl;
        }
    }
}

