#include <iostream>
#include <vector>

int main() {
    int data[ 4 ] [ 3 ] [ 10 ] = {} ;
    int n ;
    std::cin >> n ;
    for( int i = 0 ; i < n ; i++ ) {
        int b , f , r , v ;
        std::cin >> b >> f >> r >> v ;
        data[ b - 1 ] [ f - 1 ] [ r - 1 ] += v ;
    }
    
    for( int b = 0 ; b < 4 ; b++ ) {
        for( int f = 0 ; f < 3 ; f++ ) {
            for( int r = 0 ; r < 10 ; r++ ) {
                std::cout << " " << data[ b ] [ f ] [ r ] ;
            }
            std::cout << std::endl ;
        }
        if( b != 3 ) {
            std::cout << "####################" << std::endl ;
        }
    }
            
}

