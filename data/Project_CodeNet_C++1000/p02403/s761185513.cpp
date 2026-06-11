#include <iostream>

int main(int argc, const char * argv[]) {
    int h, w;
    for ( ; std::cin >> h >> w && !(h == 0 && w ==0); ) {
        for (int j = 0; j < h; j++) {
            for (int i = 0; i < w; i++) {
                std::cout << "#";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}