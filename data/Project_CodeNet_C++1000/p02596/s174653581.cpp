#include <iostream>

int main() {
    int k{};
    std::cin >> k;
    if (k % 2 == 0) {
        std::cout << -1 << std::endl;
    } else {
        int v{};
        for (int i = 1; i <= k; i++) {
            v = (10 * v + 7) % k;
            if (v == 0) {
                std::cout << i << std::endl;
                return 0;
            }
        }
        std::cout << -1 << std::endl;
    }
    return 0;
}