#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> h(n);
    rep(i, n) scanf("%d", &h[i]);

    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    rep(i, n) {
        bool ok = true;
        for (auto j: g[i]) if (h[i] <= h[j]) ok = false;
        if (ok) ans++;
    }
    printf("%d\n", ans);
    return 0;
}