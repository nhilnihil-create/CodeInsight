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
    if (n*k <= 100000) {
        std::string t;
        for (int i = 0; i < k; i++) t += s;
        int ans = 0;
        for (int i = 0; i < k*n - 1; i++) {
            if (t[i] == t[i + 1]) {
                char alph = 'a';
                while (alph == t[i] || (i < 3 * n - 2 && alph == t[i + 2])) alph++;
                t[i + 1] = alph;
                ans++;
            }
        }
        std::cout << ans << std::endl;
        return 0;
    }
    std::string t = s + s + s;
    long long a = 0, b = 0, c = 0;
    bool f = false, g = false;
    for (int i = 0; i < 3 * n - 1; i++) {
        if (t[i] == t[i + 1]) {
            char alph = 'a';
            while (alph == t[i] || (i < 3 * n - 2 && alph == t[i + 2])) alph++;
            t[i + 1] = alph;
            if (i + 1 < n) a++;
            else if (i + 1 < 2 * n) b++;
            else c++;
            f |= i + 1 == n;
            g |= i + 1 == 2 * n;
        }
    }
    if (!f || !g) std::cout << k / 2 * a + (k - 1) / 2 * b + c << std::endl;
    else std::cout << a + (k - 2)*b + c << std::endl;
    return 0;
}