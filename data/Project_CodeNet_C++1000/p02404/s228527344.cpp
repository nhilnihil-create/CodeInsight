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

                if (j == 0 || j == H - 1) {
                    std::cout << "#";
                    if (i == W - 1) {
                        std::cout << std::endl;
                    }
                } else {
                    if (i == 0 || i == W - 1) {
                        std::cout << "#";
                    } else {
                        std::cout << ".";
                    }

                    if (i == W - 1) {
                        std::cout << std::endl;
                    }
                }
            }


        }

        std::cout << std::endl;


    }

    return 0;
}