#include <iostream>
using i64 = long long;


int main() {
    int n, x, t;
    std::cin >> n >> x >> t;
    std::cout << (n + x - 1) / x * t << std::endl;

    return 0;
}
