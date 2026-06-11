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

long long gcd(const long long &a, const long long &b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int n; long long m; std::cin >> n >> m;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i] /= 2;
    }
    long long lcm = 1;
    for (int i = 0; i < n; i++) {
        lcm *= a[i] / gcd(lcm, a[i]);
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        flag &= (lcm / a[i]) & 1;
    }
    if (!flag) {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::cout << (m / lcm + 1) / 2 << std::endl;
    return 0;
}
