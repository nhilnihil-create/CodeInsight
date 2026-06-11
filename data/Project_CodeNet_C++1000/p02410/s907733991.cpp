#include <iostream>

int main()
{
    int h, w;

    std::cin >> h >> w;

    int array[w][h] = {};

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> array[j][i];
        }
    }

    int row[w] = {};
    for (int i = 0; i < w; i++) {
        std::cin >> row[i];
    }


    int ans[h] = {};
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                        ans[i] += array[j][i] * row[j];
                }
            }

    for (int i = 0; i < h; i++ ) {
        std::cout << ans[i] << std::endl;

    }

}