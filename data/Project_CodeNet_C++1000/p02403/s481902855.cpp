#include <iostream>

int main(void)
{
    while(true) {
        int h, w;
        std::cin >> h >> w;
	if(h == 0 && w == 0) { break; }
        for(int i_h = 0; i_h < h; i_h++) {
            for(int i_w = 0; i_w < w; i_w++) {
                std::cout << "#";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}