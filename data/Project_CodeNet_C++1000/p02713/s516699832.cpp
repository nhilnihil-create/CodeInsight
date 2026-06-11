#include <iostream>
#include <numeric>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;

    i64 s = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        const int g = std::gcd(i, j);
        for (int k = 1; k <= n; k++) s += std::gcd(k, g);
    }

    std::cout << s << std::endl;

    return 0;
}
