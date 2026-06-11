#include <iostream>

void print_chess(int height, int width);

int main(void)
{
    int height, width;
    while (true) {
        std::cin >> height;
        std::cin >> width;
        if (height == 0 && width == 0) {
            break;
        }
        print_chess(height, width);
    }
    return 0;
}

void print_chess(int height, int width)
{
    int i, j;
    for (i = 0; i < height; ++i) {
        if (i % 2 == 0) {
            for (j = 0; j < width; ++j) {
                if (j % 2 == 0 && j != width - 1) {
                    std::cout << "#";
                } else if (j % 2 == 1 && j != width - 1) {
                    std::cout << ".";
                } else if (j % 2 == 0 && j == width - 1) {
                    std::cout << "#" << std::endl;
                } else if (j % 2 == 1 && j == width - 1) {
                    std::cout << "." << std::endl;
                }
            }
         } else if (i % 2 == 1) {
            for (j = 0; j < width; ++j) {
                if (j % 2 == 0 && j != width - 1) {
                    std::cout << ".";
                } else if (j % 2 == 1 && j != width - 1) {
                    std::cout << "#";
                } else if (j % 2 == 0 && j == width - 1) {
                    std::cout << "." << std::endl;
                } else if (j % 2 == 1 && j == width - 1) {
                    std::cout << "#" << std::endl;
                }
            }
        }
    }
    std::cout << "" << std::endl;
}