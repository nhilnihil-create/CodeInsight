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
    std::vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; i++) std::cin >> b[i];
    std::priority_queue<std::pair<long long, int>> que;
    for (int i = 0; i < n; i++) {
        que.emplace(b[i], i);
    }
    long long ans = 0;
    while (!que.empty()) {
        int i = que.top().second;
        que.pop();
        int p = (i + n - 1) % n, q = (i + 1) % n;
        long long k = b[i] - std::max(b[p], b[q]);
        k = (k + b[p] + b[q] - 1) / (b[p] + b[q]);
        if ((b[i] - a[i]) % (b[p] + b[q]) == 0) {
            k = std::min(k, (b[i] - a[i]) / (b[p] + b[q]));
        }
        b[i] -= k*(b[p] + b[q]);
        ans += k;
        if (a[i] > b[i]) break;
        if (a[i] == b[i]) continue;
        que.emplace(b[i], i);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) ok &= a[i] == b[i];
    std::cout << (ok ? ans : -1) << std::endl;
    return 0;
}
