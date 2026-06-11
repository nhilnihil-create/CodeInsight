#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
    long double const pi = 3.14159265359;
    long double a,b;
    long double c;
    
    long double S;
    long double L;
    long double h;
    
    std::cin >> a >> b >> c;
    h = b * std::sin(c/180*pi);
    S = 0.5 * a * h;
    L = a + b + std::sqrt( a * a + b * b - 2*a*b*std::cos(c/180*pi));
    
    
    std::cout << std::setprecision(20);
    std::cout << S << std::endl;
    std::cout << L << std::endl;
    std::cout << h << std::endl;
    
    return 0;
}