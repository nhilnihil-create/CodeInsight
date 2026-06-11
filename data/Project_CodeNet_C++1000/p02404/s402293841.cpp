#include <iostream>

void print_rectangle(int& height, int& width);

int main(void)
{
    int width, height;
    while(true) {
        std::cin >> height;
        std::cin >> width;
        if (height == 0 && width == 0) {
            break;
        }
        print_rectangle(height, width);
    }
    return 0;
}

void print_rectangle(int& height, int& width)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < height; ++i) {
        if (i == 0 || i == height - 1) {
            for (j = 0; j < width - 1; ++j) {
                std::cout << "#";
            }
            if (j == width - 1) {
                std::cout << "#" << std::endl;
            }
        } else {
            for (j = 0; j < width; ++j) {
                if (j == 0) {
                    std::cout << "#";
                } else if (j == width - 1) {
                    std::cout << "#" << std::endl;
                } else {
                    std::cout << ".";
                }
            }
        }
    } 
    std::cout << "" << std::endl;
}