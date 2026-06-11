//
// Created by tac on 2016/10/12.
//

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

double circle_area(double r) {
    return M_PI * r * r;
}

double circle_length(double r) {
    return 2.0 * M_PI * r;
}

int main() {
    double r;
    std::cin >> r;
    std::cout << std::fixed << std::setprecision(6) << circle_area(r) << " " << circle_length(r) << std::endl;
    return EXIT_SUCCESS;
}