#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int ans[N] , k;
vector<pair<int , int> > adj[N];

void dfs (int node , int par , int col) {
    int nxt = 1;
    for (auto &c : adj[node]) {
        if (c.first == par) continue;
        nxt += nxt == col;
        k = max(k , nxt);
        ans[c.second] = nxt;
        dfs(c.first , node , nxt);
        nxt++;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0 ;i < n - 1 ;i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back({v , i});
        adj[v].push_back({u , i});
    }

    dfs(1 , 1 , -1);

    cout << k << '\n';
    for (int i = 0 ;i < n - 1 ;i++)
        cout << ans[i] << '\n';
}
