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
    std::vector<int> cnt(n + 2), acc(n + 2);
    for (int i = 0; i < n; i++) {
        int a; std::cin >> a;
        cnt[a]++;
    }
    std::sort(cnt.rbegin(), cnt.rend());
    for (int i = n - 1; i >= 0; i--) {
        acc[i] = cnt[i] + acc[i + 1];
    }
    auto check = [&](int w, int h) {
        int lo = -1, hi = n + 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (cnt[mid] <= w) hi = mid;
            else lo = mid;
        }
        return hi + acc[hi] / w >= h;
    };
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        int lo = 0, hi = n/i + 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, i)) lo = mid;
            else hi = mid;
        }
        std::cout << lo << std::endl;
    }
    return 0;
}
