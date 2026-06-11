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
    std::string s; std::cin >> s;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '1';
    }
    bool one = false;
    for (int i = 0; i < n; i++) one |= a[i] == 1;
    for (int i = 0; i < n; i++) {
        a[i] = one ? a[i] == 1 : a[i] == 2;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool even = (((n - 1) | i)^(n - 1)) == 0;
        ans ^= even*a[i];
    }
    if (!one) ans *= 2;
    std::cout << ans << std::endl;
    return 0;
}
