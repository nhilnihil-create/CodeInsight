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
#include <iomanip>
#include <cassert>
#include <random>


int main() {
    std::vector<long long> t(2), a(2), b(2);
    for (int i = 0; i < 2; i++) std::cin >> t[i];
    for (int i = 0; i < 2; i++) std::cin >> a[i];
    for (int i = 0; i < 2; i++) std::cin >> b[i];
    std::vector<long long> d(2);
    for (int i = 0; i < 2; i++) d[i] = t[i]*(a[i] - b[i]);
    d[1] += d[0];
    if (d[1] == 0) {
        std::cout << "infinity" << std::endl;
        return 0;
    }
    if ((d[0] > 0) ^ (d[1] < 0)) {
        std::cout << 0 << std::endl;
        return 0;
    }
    long long sa = t[0] * a[0] + t[1] * a[1];
    long long sb = t[0] * b[0] + t[1] * b[1];
    if (sa < sb) {
        std::swap(sa, sb);
        std::swap(a, b);
    }
    long long k = t[1] * (a[1] - b[1]) / (sa - sb);
    std::cout << 2 * k - 1 - ((t[1] * (a[1] - b[1])) % (sa - sb) == 0) << std::endl;
    return 0;
}