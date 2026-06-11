#include <iostream>

main(){
        int w, h, x, y, r;

        std::cin >> w >> h >> x >> y >> r;

        if( ( x >= r && w - x >= r ) && ( y >= r && h - y >= r ) ){
                std::cout << "Yes" << std::endl;
        } else {
                std::cout << "No" << std::endl;
        }

}