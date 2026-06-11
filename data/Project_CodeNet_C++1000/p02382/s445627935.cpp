#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

double manhattan(int n, int* x, int* y, double p)
{
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += std::pow(abs(x[i] - y[i]), p);
    }

    return std::pow(sum, 1.0/p);
}

double chebyshev(int n, int*x, int* y)
{
    int max = -1;
    for (int i = 0; i < n; ++i) {
        if (max < abs(x[i] - y[i])) {
            max = abs(x[i] - y[i]);
        }
    }
    return (double)max;
}

int main()
{
    std::size_t n;
    std::cin >> n;

    int x[n] = {};
    for (std::size_t i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    int y[n] = {};
    for (std::size_t i = 0; i < n; ++i) {
        std::cin >> y[i];
    }

    std::cout << std::fixed << std::setprecision(20) << manhattan(n, x, y, 1.0) << std::endl;
    std::cout << std::fixed << std::setprecision(20) << manhattan(n, x, y, 2.0) << std::endl;
    std::cout << std::fixed << std::setprecision(20) << manhattan(n, x, y, 3.0) << std::endl;
    std::cout << std::fixed << std::setprecision(20) << chebyshev(n, x, y) << std::endl;

    return 0;
}
