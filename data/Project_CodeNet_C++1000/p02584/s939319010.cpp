#include <iostream>
#include <cstdlib>
using i64 = long long;

int main() {
    i64 x, k, d;
    std::cin >> x >> k >> d;
    if (x < 0) x = -x;

    if (x / d > k) {
        x -= d * k;
        std::cout << x << std::endl;
        return 0;
    }

    const int c = x / d;
    k -= c;
    x -= c * d;

    std::cout << (k % 2 ? d - x : x) << std::endl;

    return 0;
}
