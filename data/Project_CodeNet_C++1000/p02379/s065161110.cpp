//
// Created by tac on 2016/10/18.
//

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

namespace {

double distance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

}

int main() {
    double x1, x2, y1, y2;

    std::cin >> x1 >> x2 >> y1 >> y2;
    std::cout << std::fixed << std::setprecision(8) << distance(x1, x2, y1, y2);

    return EXIT_SUCCESS;
}