#include <iostream>
#include <iomanip>
int main() {
    int a , b ;
    std::cin >> a >> b ;
    std::cout << a / b << " " ;
    std::cout << a % b << " " ;
    std::cout << std::fixed << std::setprecision( 5 ) << (double)a / b << std::endl ;
    
    
}

