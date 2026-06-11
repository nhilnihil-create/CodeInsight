#pragma gcc optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> f(n + 1, -1);
    int ans = 1;
    function<int(int)> find = [&] (int x) {
        return f[x] < 0 ? x : f[x] = find(f[x]);
    };
    auto merge = [&] (int x, int y) {
        if ((x = find(x)) == (y = find(y))) return;
        if (x > y) swap(x, y);
        f[x] += f[y];
        f[y] = x;
        ans = max(ans, -f[x]);
    };
    while (m--) {
        int u, v; cin >> u >> v;
        merge(u, v);
    }
    cout << ans << '\n';
}