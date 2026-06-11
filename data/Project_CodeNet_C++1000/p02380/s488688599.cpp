#include <iostream>
#include <cmath>

int main(int argc, const char *argv[]) {
    static const double pi = 3.141592653589793;
    int a, b, c;
    std::cin >> a >> b >> c;
    double s = 0.5 * a * b * std::sin(pi * c / 180);
    double l = a + b + std::sqrt(std::pow(a, 2.0) + std::pow(b, 2.0) - 2.0 * a * b * std::cos(pi * c / 180));
    double h = b * std::sin(pi * c / 180);
    std::cout << std::fixed << s << std::endl;
    std::cout << std::fixed << l << std::endl;
    std::cout << std::fixed << h << std::endl;
    return 0;
}