#include <bits/stdc++.h>

typedef long long ll;
const int maxn = 2e5 + 3;
const ll mo = 1e9 + 7;

int n, m, p[maxn], clk, lk[maxn], la[maxn], lr[maxn], d[maxn], cs[maxn];
ll ans;
std::vector<int> E[maxn];
std::vector<int> dla[maxn];

void dfs(int u) {
    la[u] = clk;
    lk[clk++] = u;
    dla[d[u]].push_back(la[u]);
    int cd12 = (p[u] ? 1 : 0) + (p[p[u]] ? 1 : 0) + cs[p[u]];
    if(cd12 >= m) {
        puts("0");
        exit(0);
    }
    ans = ans * ll(m - cd12) % mo;
    for(auto &&v : E[u]) {
        if(v == p[u])
            continue;
        p[v] = u;
        d[v] = d[u] + 1;
        dfs(v);
        cs[u] += 1;
    }
    lr[u] = clk;
}

int main() {
    ans = 1;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}