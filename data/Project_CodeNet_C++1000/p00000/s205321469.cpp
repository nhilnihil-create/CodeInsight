#include <iostream>

auto main() -> int {
    for (int x = 1; x <= 9; x++) {
        for (int y = 1; y <= 9; y++) {
            std::cout << x << "x" << y << "=" << (x*y) << std::endl;
        }
    }
    return 0;
}