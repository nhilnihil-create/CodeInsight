#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
    double x1,y1,x2,y2;
    double d;
    std::cin >> x1 >> y1 >> x2 >> y2;
    d = std::sqrt((x1 - x2) * ( x1 - x2) + ( y1- y2) * (y1 - y2));
    std::cout << std::setprecision(20) << d << std::endl;
    return 0;
}