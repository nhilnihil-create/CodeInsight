#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;

const int N = 2e5 + 5;
int par[N], sz[N];
int n, m;

void init() {
    for (int i = 1; i < N; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
}

void make(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        make(u, v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, sz[find(i)]);
    }
    cout << ans << '\n';
    return 0;
}