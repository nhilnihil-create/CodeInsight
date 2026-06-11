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
    int n; std::cin >> n;
    std::vector<std::pair<long long, long long>> e;
    for (int i = 0; i < n; i++) {
        long long x, l; std::cin >> x >> l;
        e.emplace_back(x - l, x + l);
    }
    std::sort(e.begin(), e.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });
    long long ans = 0, prev = -1e18;
    for (int i = 0; i < n; i++) {
        if (prev <= e[i].first) {
            ans++;
            prev = e[i].second;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}