#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<std::complex<double>> v;
    for (int i = 0; i < n; i++) {
        double x, y;
        std::cin >> x >> y;
        v.emplace_back(x, y);
    }
    std::sort(v.begin(), v.end(), [](auto lhs, auto rhs) { return std::arg(lhs) < std::arg(rhs); });
    double ret = 0;
    for (int i = 0; i < n; i++) {
        std::complex<double> p;
        for (int j = 0; j < n; j++) {
            p += v[(i + j) % n];
            ret = std::max(ret, std::abs(p));
        }
    }

    std::cout << std::fixed << std::setprecision(12) << ret << std::endl;

    return 0;
}
