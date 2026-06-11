#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

constexpr int MOD = 1000000007;

template <typename T> void bfs(const vector<vector<T>>& G, int i, vector<bool>& seen, vector<T>& in_dgree, vector<T>& ans) {
    queue<int> q;
    q.push(i);
    seen[i] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        ans.push_back(v);
        for (auto u : G[v]) {
            --in_dgree[u];
            if ((!seen[u]) && in_dgree[u] == 0) {
                q.push(u);
                seen[u] = true;
            }
        }
    }
}

template <typename T> void topological_sort(const vector<vector<T>>& G, vector<T>& in_dgree) {
    int v = G.size();
    vector<bool> seen(v, false);
    vector<T> ans;
    rep(i, 0, v) {
        if ((!seen[i]) && in_dgree[i] == 0) { bfs(G, i, seen, in_dgree, ans); }
    }
    for (auto v : ans) { cout << v << endl; }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int v, e;
    cin >> v >> e;

    vvi G(v);
    vi in_dgree(v, 0);
    rep(i, 0, e) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        ++in_dgree[t];
    }
    // for (auto v : in_dgree) { cout << v << endl; }

    topological_sort(G, in_dgree);

    return 0;
}
