#include <iostream>
#include <iomanip>
#include <cmath>
int main() {
    int n, a[100];
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    double s1 = 0., s2 = 0., s3 = 0., si = 0.;
    for (int i = 0, b, b2; i < n; ++i) {
        std::cin >> b;
        b = std::abs(a[i] - b);
        si = std::max(static_cast<double>(b), si);
        s1 += b;
        b2 = b * b;
        s2 += b2;
        s3 += b2 * b;
    }
    std::cout << std::fixed << std::setprecision(6)
        << s1 << std::endl
        << std::sqrt(s2) << std::endl
        << std::cbrt(s3) << std::endl
        << si << std::endl;
}

