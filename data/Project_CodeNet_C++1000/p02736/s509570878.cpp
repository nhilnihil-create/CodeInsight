#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> a;
    for (int i = 1; i < n; i++) a.push_back(abs(s[i] - s[i - 1]));

    bool f = std::find(a.begin(), a.end(), 1) != a.end();
    if (f) for (auto &e : a) e &= 1;
    else for (auto &e : a) e >>= 1;

    bool g = false;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] && n - 2 == (i | (n - 2 - i))) g = !g;
    }

    std::cout << (f ? 1 : 2) * (g ? 1 : 0) << std::endl;

    return 0;
}
