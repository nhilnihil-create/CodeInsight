//
// Created by tac on 2016/10/12.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>

int main() {
    int a, b;
    int d, r;
    double f;
    std::cin >> a >> b;
    d = a / b;
    r = a % b;
    f = static_cast<double>(a) / b;
    std::cout << d << " " << r << " " << std::fixed << std::setprecision(6) << f << std::endl;
    return EXIT_SUCCESS;
}