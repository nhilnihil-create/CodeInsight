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
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    int ans = a[n - 1] - a[0];
    for (int i = 1; i < n - 1; i++) {
        ans += std::abs(a[i]);
    }
    std::cout << ans << std::endl;
    int cur = a[0];
    for (int i = n - 2; i > 0; i--) {
        if (a[i] < 0) break;
        std::cout << cur << " " << a[i] << std::endl;
        cur -= a[i];
    }
    std::cout << a[n - 1] << " " << cur << std::endl;
    cur = a[n - 1] - cur;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] >= 0) break;
        std::cout << cur << " " << a[i] << std::endl;
        cur -= a[i];
    }
    return 0;
}
