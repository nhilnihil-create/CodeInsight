#include <iostream>
#include <iomanip>
#include <cmath>
int main() {
    int n, s[1000];
    for (std::cin >> n; n != 0; std::cin >> n) {
        double m = 0., d = 0.;
        for (int i = 0; i < n; ++i) {
            std::cin >> s[i];
            m += s[i];
        }
        m /= n;
        for (int i = 0; i < n; ++i) {
            d += (s[i] - m) * (s[i] - m);
        }
        d /= n;
        std::cout << std::fixed << std::setprecision(6)
            << std::sqrt(d) << std::endl;
    }
}

