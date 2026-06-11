//
// Created by tac on 2016/10/22.
//

#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

namespace {

double distance(std::vector<double> x, std::vector<double> y, int p) {
    double d = 0.0;
    auto size = x.size();
    for (int i = 0; i < size; ++i) {
        d += std::pow(std::abs(x[i] - y[i]), p);
    }

    return std::pow(d, 1.0 / p);
}

double distance_inf(std::vector<double> x, std::vector<double> y) {
    double max_value = -1;
    auto size = x.size();
    for (int i = 0; i < size; ++i) {
        max_value = std::max(max_value, std::abs(x[i] - y[i]));
    }
    return max_value;
}


}

int main() {
    int n;
    std::vector<double> x;
    std::vector<double> y;
    int s;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> s;
        x.push_back(s);
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> s;
        y.push_back(s);
    }
    std::cout << std::fixed << std::setprecision(6);
    std::cout << distance(x, y, 1) << std::endl;
    std::cout << distance(x, y, 2) << std::endl;
    std::cout << distance(x, y, 3) << std::endl;
    std::cout << distance_inf(x, y) << std::endl;

    return EXIT_SUCCESS;
}