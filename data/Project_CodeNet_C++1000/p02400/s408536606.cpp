#include <iostream>
#include <iomanip>
#include <cmath>
int main(){
    double r;
    std::cin >> r;
    std::cout << std::fixed <<std::setprecision(6) << M_PI * r * r << " " <<2*M_PI*r << std::endl;
    return 0;
}
