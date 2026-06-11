//
// Created by tac on 2016/10/19.
//

#include <cstdlib>
#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <cmath>

namespace {

double mean(const std::vector<double> &vec) {
    return std::accumulate(vec.cbegin(), vec.cend(), 0.0) / vec.size();
}

double dispersion(const std::vector<double> &vec) {
    double m = mean(vec);
    double d = std::accumulate(vec.cbegin(), vec.cend(), 0.0, [m](double init, double s) {
        return init + std::pow(s - m, 2);
    });
    return std::sqrt(d / vec.size());
}

}

int main() {
    int n;
    int s;

    while (true) {
        std::cin >> n;
        if (n <= 0) {
            break;
        }
        std::vector<double> vec {};
        for (int i = 0; i < n; ++i) {
            std::cin >> s;
            vec.push_back(s);
        }
        std::cout << std::fixed << std::setprecision(8);
        std::cout << dispersion(vec) << std::endl;
    }

    return EXIT_SUCCESS;
}