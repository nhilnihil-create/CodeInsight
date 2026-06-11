#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using Graph = vector< vector<int> >;

bool dfs(int cur, vector<int>& memo, Graph& g, vector<int>& order) {
    memo[cur] = 1;
    for (int nex : g[cur]) {
        if (memo[nex] == 2) continue;
        if (memo[nex] == 1) return false;
        if (!dfs(nex, memo, g, order)) return false;
    }
    memo[cur] = 2;
    order.push_back(cur);
    return true;
}

bool tsort(Graph& g, vector<int>& order) {
    vector<int> memo(g.size(), 0);
    for (int i = 0; i < g.size(); i++) {
        if (memo[i] != 0) continue;
        if (!dfs(i, memo, g, order)) return false;
    }
    reverse(order.begin(), order.end());
    return true;
}

const int INF = 1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector< vector<int> > a(n, vector<int>(n - 1));
    Graph g(n * n);
    vector<int> deg(n * n, 0);
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < n - 1; j++) {
            cin >> a[i][j];
            a[i][j]--;

            int v1 = i;
            int v2 = a[i][j];
            if (v1 > v2) swap(v1, v2);
            tmp.push_back(v1 * n + v2);
        }

        for (int j = 0; j < n - 2; j++) {
            g[tmp[j]].push_back(tmp[j + 1]);
            deg[tmp[j + 1]]++;
        }
    }

    vector<int> order;
    bool can = tsort(g, order);
    if (!can) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> dists(n * n, 0);
    for (int cur : order) {
        for (int nex : g[cur]) {
            dists[nex] = max(dists[nex], dists[cur] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, dists[i * n + j]);
        }
    }
    ans++;
    cout << (ans >= INF ? -1 : ans) << endl;
    return 0;
}
