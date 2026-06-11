// 6/30 解き直し
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

Graph G;
vector<int> points;
vector<int> ans;

void dfs(int v, int sum, int p) {
    ans[v] = sum + points[v];
    for (auto nv : G[v]) {
        if (nv == p) continue;
        dfs(nv, ans[v], v);
    }
    return;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    G.resize(N);
    rep(i, N-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    points.resize(N, 0);

    while (Q--) {
        int p, x;
        cin >> p >> x;
        p--;
        points[p] += x;
    }

    ans.resize(N, 0);

    dfs(0, 0, -1);

    for (auto a : ans) cout << a << endl;
}