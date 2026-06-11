#include <iostream>

int main()
{
    while(1) {
        int H,W;
        std::cin >> H >> W;

        if (H == 0 && W == 0){
            break;
            }

        for (int j = 0; j < H; j++) {
            for (int i = 0; i < W; i++) {
                std::cout << "#";
                if (i == W - 1) {
                    std::cout << std::endl;
                }
            }
        }

        std::cout << std::endl;
    }

    return 0;
}