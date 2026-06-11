#include <iostream>
#include <cmath>
#include <iomanip>
int main() {
    double a, b, c, pi = M_PI;
    std::cin >> a >> b >> c;
    c = c * pi / 180;
    std::cout << std::fixed << std::setprecision(6)
        << a / 2 * b * std::sin(c) << std::endl
        << a + b + std::sqrt(a * a + b * b - 2 * a * b * std::cos(c)) << std::endl
        << b * std::sin(c) << std::endl;
}

