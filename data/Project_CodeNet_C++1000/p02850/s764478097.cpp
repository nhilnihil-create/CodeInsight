#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

struct Edge {
    int to, id;
};

int n;
vector<vector<Edge>> g;
vector<int> ans;

void dfs(int v, int c = -1, int pa = -1) {
    int k = 1;
    for (auto nv : g[v]) {
        if (nv.to == pa) continue;
        if (c == k) ++k;

        ans[nv.id] = k;
        dfs(nv.to, k, v);
        ++k;
    }
}

int main() {

    cin >> n;
    g.resize(n);
    ans.resize(n - 1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;

        g[a].push_back(Edge({b, i}));
        g[b].push_back(Edge({a, i}));
    }

    //どの点から始めても良い
    dfs(0);

    int mx = 0;
    for (int i = 0; i < n - 1; ++i) {
        mx = max(mx, ans[i]);
    }

    cout << mx << endl;

    for (int i = 0; i < n - 1; ++i) {
        cout << ans[i] << endl;
    }
}