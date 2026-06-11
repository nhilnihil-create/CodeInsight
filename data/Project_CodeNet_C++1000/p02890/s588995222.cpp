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
    std::vector<int> cnt(n + 2);
    for (int i = 0; i < n; i++) {
        int a; std::cin >> a;
        cnt[a]++;
    }
    std::sort(cnt.rbegin(), cnt.rend());
    std::vector<int> overw(n + 2), acc(n + 2);
    for (int i = n; i > 0; i--) {
        overw[i] = overw[i + 1];
        while (cnt[overw[i]] >= i) overw[i]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        acc[i] = cnt[i] + acc[i + 1];
    }
    for (int h = 1; h <= n; h++) {
        int lo = 0, hi = n / h + 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (overw[mid] + acc[overw[mid]] / mid >= h) lo = mid;
            else hi = mid;
        }
        std::cout << lo << std::endl;
    }
    return 0;
}
