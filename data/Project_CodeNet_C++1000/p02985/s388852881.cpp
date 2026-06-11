#include <iostream>
#include <vector>
using namespace std;
using llong = long long;

const llong mod = (llong)(1e9) + 7;
llong n, k;
vector<vector<llong>> tree;
vector<llong> par;
vector<llong> sz;

llong dfs(int u, int k, int depth) {
    llong ret = 1;
    if (depth >= 2) k += sz[par[u]];
    if (depth >= 3) k++;
    ret *= k;
    ret %= mod;

    llong cnt = 0;
    for (auto v:tree[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        sz[v] = cnt;
        cnt++;
        ret *= dfs(v, k - cnt, depth + 1);
        ret %= mod;
    }
    return ret;
}

int main() {
    cin >> n >> k;
    tree.resize(n + 1);
    par.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        llong a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    cout << dfs(1, k, 0) << endl;
    return 0;
}