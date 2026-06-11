#include <iostream>

int main()
{
    int h = 0;
    int w = 0;
    std::cin >> h >> w;

    int array[w+1][h+1] = {};

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> array[j][i];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
             array[w][i] += array[j][i];
             array[j][h] += array[j][i];

        }
    }
    for (int i = 0; i < h; i++) {
        array[w][h] += array[w][i];
    }

    for (int i = 0; i < h + 1; i++) {
        for (int j = 0; j < w + 1; j++) {
            std::cout << array[j][i];
            if (j < w) {
                std::cout << " ";
            }
            if (j == w) {
                std::cout  << std::endl;
            }
        }
    }

    return 0;

}