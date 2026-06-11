#include <iostream>

int main() {
    while( true ) {
        int h , w ;
        std::cin >> h >> w ;
        if( ! ( h | w ) ) {
            break ;
        } else {
            for( int i = 0 ; i < h ; i++ ) {
                for( int ii = 0 ; ii < w ; ii++ ) {
                    if( ( i + ii ) % 2 == 0 ) {
                        std::cout << "#" ;
                    } else {
                        std::cout << "." ;
                    }
                }
                std::cout << std::endl ;
            }
            std::cout << std::endl ;
        }
    }
}


