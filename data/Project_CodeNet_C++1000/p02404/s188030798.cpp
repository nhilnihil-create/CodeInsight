#include <iostream>
int main() {
    int h, w;
    for (std::cin >> h >> w; h != 0 || w != 0; std::cin >> h >> w) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                char c;
                if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                    c = '#';
                } else {
                    c = '.';
                }
                std::cout << c;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

