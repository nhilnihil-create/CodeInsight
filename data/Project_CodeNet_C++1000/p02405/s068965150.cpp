//
// Created by tac on 2016/10/12.
//

#include <cstdlib>
#include <iostream>

int main() {
    int h, w;
    while (true) {
        std::cin >> h >> w;
        if (h <= 0 && w <= 0) {
            break;
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if ((i % 2 == 0 && j % 2 == 0) || (i % 2 ==1 && j %2 == 1)) {
                    std::cout << "#";
                } else {
                    std::cout << ".";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}