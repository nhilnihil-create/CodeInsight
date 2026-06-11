#include <iostream>
#include <cmath>

int main(int argc, const char *argv[]) {
    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << std::fixed << std::sqrt(std::pow(x2 - x1, 2.0) + std::pow(y2 - y1, 2.0)) << std::endl;
    return 0;
}