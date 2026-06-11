#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    double a, b, c;
    std::cin >> a >> b >> c;
    c *= M_PI/180;
    std::cout << std::fixed << std::setprecision(6) << a*b*std::sin(c)/2 << "\n";
    std::cout << std::fixed << std::setprecision(6) << a+b+std::sqrt(a*a+b*b-2*a*b*std::cos(c)) << "\n";
    std::cout << std::fixed << std::setprecision(6) << b*std::sin(c) << "\n";
    return 0;
}