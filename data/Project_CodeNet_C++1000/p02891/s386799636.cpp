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
    std::string s; std::cin >> s;
    long long k; std::cin >> k;
    int n = s.size();
    bool same = true;
    for (int i = 0; i < n - 1; i++) same &= s[i] == s[i + 1];
    if (same) {
        std::cout << k*n / 2 << std::endl;
        return 0;
    }
    if (k <= 3) {
        std::string t;
        for (int i = 0; i < k; i++) t += s;
        long long ans = 0;
        for (int i = 0; i < k*n - 1; i++) {
            if (t[i] == t[i + 1]) {
                ans++;
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == t[i] || (i < k*n - 2 && c == t[i + 2])) continue;
                    t[i + 1] = c;
                    break;
                }
            }
        }
        std::cout << ans << std::endl;
        return 0;
    }
    std::string t = s + s + s;
    long long a = 0, b = 0, c = 0;
    long long cnt = 1;
    for (int i = 1; i < 3 * n; i++) {
        if (t[i] == t[i - 1]) cnt++;
        else {
            if (i < n) a += cnt/2;
            else if (i < 2*n) b += cnt/2;
            else c += cnt/2;
            cnt = 1;
        }
    }
    c += cnt / 2;
    std::cout << a + (k - 2)*b + c << std::endl;
    return 0;
}
