#include <bits/stdc++.h>
using i64 = long long;

int main() {
    i64 t, a, b, s, c, d;
    std::cin >> t >> s >> a >> b >> c >> d;

    i64 d1 = t * (a - c),
        d2 = t * a + s * b - t * c - s * d,
        dd = llabs(d2 - d1);
    if (d2) {
        if ((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0)) {
            d1 = d1 < 0 ? -d1 : d1;
            d2 = d2 < 0 ? -d2 : d2;
            i64 q = (d1 + d2) / d2, r = q * d2 - dd;
            std::cout << 2 * q - 3 + (r == 0 ? 1 : r < 0 ? 2 : 0) << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    } else {
        std::cout << "infinity" << std::endl;
    }

    return 0;
}
