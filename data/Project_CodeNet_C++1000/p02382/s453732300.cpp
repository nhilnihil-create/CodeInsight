#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

double ab(double x) {
    return x < 0 ? -x : x;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<double> x;
    std::vector<double> y;

    for (int i = 0; i < n; i++) {
        double t;
        std::cin >> t;
        x.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        double t;
        std::cin >> t;
        y.push_back(t);
    }
    double d1, d2, d3, di;
    d1 = 0;
    d2 = 0;
    d3 = 0;
    di = 0;
    for (int i = 0; i < n; i++) {
        double t = ab(x[i] - y[i]);
        d1 += t;
        d2 += t*t;
        d3 += t * t*t;
        if (t > di)
            di = t;
    }
    d2 = std::sqrt(d2);
    d3 = std::pow(d3, double(1.0 / 3.0));

    std::cout << std::setprecision(20);
            std::cout << d1 << std::endl << d2 << std::endl << d3 << std::endl << di << std::endl;


    return 0;
}