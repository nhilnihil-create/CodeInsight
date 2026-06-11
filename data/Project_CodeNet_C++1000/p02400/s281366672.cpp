#include <iostream>
#include <iomanip>
#include <cmath>
int main() {
    double r;
    std::cin >> r;
    double pi = std::acos(-1.);
    std::cout << std::fixed << std::setprecision(6)
    << pi * r * r << ' ' << 2 * pi * r << std::endl;
}

