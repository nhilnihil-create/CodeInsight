#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <cassert>
#include <random>


long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long ret = extgcd(b, a%b, x, y);
    std::tie(x, y) = std::make_pair(y, x - a / b * y);
    return ret;
}


std::pair<long long, long long> crt(long long m1, long long r1, long long m2, long long r2) {
    long long x = 0, y = 0;
    long long d = extgcd(m1, m2, x, y);
    if (r1%d != r2%d) {
        return { -1, -1 };
    }
    long long mod = m1 / d * m2;
    long long rem = r1 + (r2 - r1) / d * m1 * x;
    rem = (rem % mod + mod) % mod;
    return { mod, rem };
}


int main() {
    int n; long long m; std::cin >> n >> m;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    long long mod = a[0], rem = a[0] / 2;
    for (int i = 1; i < n; i++) {
        std::tie(mod, rem) = crt(mod, rem, a[i], a[i] / 2);
        if (mod == -1) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }
    std::cout << m / mod + (rem > 0 && m % mod >= rem) << std::endl;
    return 0;
}
