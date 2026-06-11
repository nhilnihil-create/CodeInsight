#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> y[i];
    }

    double p1, p2, p3, pinf;

    p1 = p2 = p3 = pinf = 0;

    for (int i = 0; i < n; i++) {
        p1 += std::abs(x[i] - y[i]);
    }

    for (int i = 0; i < n; i++) {
        p2 += std::abs(x[i] - y[i]) * std::abs(x[i] - y[i]);
    }
    p2 = std::sqrt(p2);

    for (int i = 0; i < n; i++) {
        p3 += std::abs(x[i] - y[i]) * std::abs(x[i] - y[i]) * std::abs(x[i] - y[i]);
    }

    double low = 0, high = 100000000000;
    for (int i = 0; i < 1000; i++) {
        double mid = (low + high) / 2;
        if (mid * mid * mid <= p3) {
            low = mid;
        } else {
            high = mid;
        }
    }

    p3 = low;

    for (int i = 0; i < n; i++) {
        pinf = std::max(pinf, std::abs(1.0 * x[i] - y[i]));
    }

    std::cout << std::fixed << std::setprecision(10);
    std::cout << p1 << std::endl << p2 << std::endl << p3 << std::endl << pinf << std::endl;

    return 0;
}