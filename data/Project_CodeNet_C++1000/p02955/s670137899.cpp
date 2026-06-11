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
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    int sum = std::accumulate(a.begin(), a.end(), 0);
    std::vector<int> b;
    auto check = [&](int m) -> bool {
        b.clear();
        for (int i = 0; i < n; i++) b.push_back(a[i] % m);
        std::sort(b.rbegin(), b.rend());
        int c = std::accumulate(b.begin(), b.end(), 0) / m;
        return std::accumulate(b.begin() + c, b.end(), 0) <= k;
    };
    int ans = 0;
    for (int i = 1; i*i <= sum; i++) {
        if (sum%i != 0) continue;
        if (check(i)) ans = std::max(ans, i);
        if (check(sum / i)) ans = std::max(ans, sum / i);
    }
    std::cout << ans << std::endl;
    return 0;
}
