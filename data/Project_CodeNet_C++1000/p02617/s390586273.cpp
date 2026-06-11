#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    ll ans = 0;
    ll s = 0;
    for (int i = 0; i < n; i++) {
        s += i + 1;
        for (int j : g[i]) {
            if (j < i) {
                s -= j + 1;
            }
        }
        ans += s;
    }

    cout << ans << '\n';
    return 0;
}