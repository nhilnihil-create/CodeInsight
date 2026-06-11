#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int N, Q;
Graph G;

void dfs(int v, int p, vector<ll> &res) {
    if (p != -1) res[v] += res[p];
    for (auto e : G[v]) {
        if (e == p) continue;
        dfs(e, v, res);
    }
}

int main() {
    cin >> N >> Q;
    G.assign(N, vector<int>());
    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> val(N, 0);
    for (int i = 0; i < Q; ++i) {
        int p, x;
        cin >> p >> x;
        --p;
        val[p] += x;
    }
    dfs(0, -1, val);
    for (auto v : val) cout << v << " ";
    cout << endl;
}