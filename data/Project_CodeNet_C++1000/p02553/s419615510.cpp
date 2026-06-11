#include <iostream>
#include <algorithm>
using i64 = long long;

int main() {
    i64 a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << std::max({
        a * c,
        b * c,
        a * d,
        b * d,
    }) << std::endl;

    return 0;
}
