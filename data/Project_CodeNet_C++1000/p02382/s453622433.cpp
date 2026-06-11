#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int n, x[1000], y[1000];
    std::cin >> n;
    for (int i=0;i<n;++i)
        std::cin >> x[i];
    for (int i=0;i<n;++i)
        std::cin >> y[i];
    double ans[4];
    for (int i=0;i<n;++i) {
        int abs = std::abs(x[i] - y[i]);
        ans[0] += abs;
        ans[1] += std::pow(abs, 2);
        ans[2] += std::pow(abs, 3);
        if (ans[3] < abs) ans[3] = abs;
    }
    ans[1] = std::pow(ans[1], 0.5);
    ans[2] = std::pow(ans[2], 1.0/3);
    for (int i=0;i<4;++i)
        std::cout << std::fixed << std::setprecision(6) << ans[i] << std::endl;
    return 0;
}
