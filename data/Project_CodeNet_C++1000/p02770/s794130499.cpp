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
    int k, q; std::cin >> k >> q;
    std::vector<long long> d(k), e(k);
    for (int i = 0; i < k; i++) std::cin >> d[i];
    while (q--) {
        long long n, x, m; std::cin >> n >> x >> m;
        for (int i = 0; i < k; i++) e[i] = d[i] % m == 0 ? m : d[i] % m;
        long long sum = std::accumulate(e.begin(), e.end(), 0LL);
        sum *= (n - 1) / k;
        for (int i = 0; i < (n - 1) % k; i++) sum += e[i];
        std::cout << n - 1 - (x + sum) / m + x / m << std::endl;
    }
    return 0;
}