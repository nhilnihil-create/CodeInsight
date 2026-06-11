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
    std::vector<long long> d(k), dm(k);
    for (int i = 0; i < k; i++) std::cin >> d[i];
    while (q--) {
        long long n, x, m; std::cin >> n >> x >> m;
        x %= m;
        for (int i = 0; i < k; i++) dm[i] = d[i] % m == 0 ? m : d[i] % m;
        long long sum = std::accumulate(dm.begin(), dm.end(), 0LL);
        long long len = (n - 1) / k;
        long long y = x + sum*len
            + std::accumulate(dm.begin(), dm.begin() + (n - 1) % k, 0LL);
        long long ng = y / m;
        std::cout << n - 1 - ng << std::endl;
    }
    return 0;
}
