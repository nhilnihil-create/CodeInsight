#include <iostream>

int main() {
    uint64_t h, w;

    std::cin >> h >> w;

    if (h == 1 || w == 1) {
        std::cout << 1 << std::endl;
    } else {
        uint64_t first_line = w / 2 + w % 2;
        uint64_t second_line = w / 2;

        uint64_t ans = first_line * (h / 2) + second_line * (h / 2) + first_line * (h % 2);

        std::cout << ans << std::endl;
    }

    return 0;
}