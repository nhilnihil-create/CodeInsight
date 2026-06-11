#include <iostream>

int main() {
    while( true ) {
        int h , w ;
        std::cin >> h >> w ;
        if( h == 0 && w == 0 ) {
            break ;
        } else {
            for( int i = 0 ; i < h ; i++ ) {
                for( int ii = 0 ; ii < w ; ii++ ) {
                    std::cout << "#" ;
                }
                std::cout << std::endl ;
            }
            std::cout << std::endl ;
        }
    }
}
