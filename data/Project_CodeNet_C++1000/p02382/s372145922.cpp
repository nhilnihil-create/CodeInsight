#include <iostream>
#include <cmath>

double distance(int x[], int y[], int n, int p) {
    double d = 0.0;
    if (p > 0) {
        for (int i = 0; i < n; i++) {
            d += std::pow(std::abs(x[i] - y[i]), p);
        }
        d = std::pow(d, 1.0 / p);
    } else {
        for (int i = 0; i < n; i++) {
            d = std::max(d, std::abs(x[i] - y[i]));
        }
    }
    return d;
}

int main(int argc, const char *argv[]) {
    int n;
    std::cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> y[i];
    }
    std::cout << std::fixed << distance(x, y, n, 1) << std::endl;
    std::cout << std::fixed << distance(x, y, n, 2) << std::endl;
    std::cout << std::fixed << distance(x, y, n, 3) << std::endl;
    std::cout << std::fixed << distance(x, y, n, 0) << std::endl;
    return 0;
}