#include <iostream>

int main() {
    for( int i = 1 ; i <= 9 ; i++ ) {
        for( int ii = 1 ; ii <= 9 ; ii++ ) {
            std::cout << i << "x" << ii << "=" << i * ii << std::endl ;
        }
    }
}

