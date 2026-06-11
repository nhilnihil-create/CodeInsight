#include <iostream>
#include <cmath>
 
int main(int argc, const char *argv[]) {
    double m, a;
    for (int n; std::cin >> n && n != 0; ) {
        int s[n];
        for (int i = 0; i < n; i++) {
            std::cin >> s[i];
        }
        m = 0;
        for (int i = 0; i < n; i++) {
            m += s[i];
        }
        m /= n;
        a = 0;
        for (int i = 0; i < n; i++) {
            a += std::pow(s[i] - m, 2.0);
        }
        a = std::sqrt(a / n);
        std::cout << std::fixed << a << std::endl;
    }
    return 0;
}