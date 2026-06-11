//
// Created by tac on 2016/10/18.
//

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

namespace {

double area(double a, double b, double deg) {
    return a * b * std::sin(deg * M_PI / 180.0) / 2.0;
}

double length(double a, double b, double deg) {
    return a + b + std::sqrt(a * a + b * b - 2 * a * b * std::cos(deg * M_PI / 180.0));
}

double hight(double a, double b, double deg) {
    return b * std::sin(deg * M_PI / 180.0);
}

}

int main() {
    int a, b, deg;

    std::cin >> a >> b >> deg;
    std::cout << std::fixed << std::setprecision(8);
    std::cout << area(a, b, deg) << std::endl;
    std::cout << length(a, b, deg) << std::endl;
    std::cout << hight(a, b, deg) << std::endl;

    return EXIT_SUCCESS;
}