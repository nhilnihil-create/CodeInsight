#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double r ;
    std::cin >> r ;
    std::cout << std::fixed << std::setprecision( 6 ) << r * r * M_PI << " " << 2 * r * M_PI << std::endl ;
    
}
