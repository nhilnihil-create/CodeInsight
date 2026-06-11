#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<vector<int>> G;
vector<int> cnt;
int n, q;
void dfs(int v, int prev) {
    if (prev != -1) cnt[v] += cnt[prev];
    for (auto nxt: G[v]) {
        if (nxt == prev) continue;
        dfs(nxt, v);
    }
}
int main() {
    cin >> n >> q;
    parent.assign(n, -1);
    G.assign(n, vector<int>());
    cnt.assign(n, 0);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < q; i++) {
        int p, x;
        cin >> p >> x;
        cnt[p-1] += x;
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        cout << cnt[i];
        if (i < n-1) cout << ' ';
    }
    cout << endl;
    return 0;
}