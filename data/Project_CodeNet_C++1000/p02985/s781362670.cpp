#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7;
vector<int> adj[N];
int n , k , ans;

int mul(int x) {
    ans = (ans * 1ll * x) % MOD;
}

void solve (int node , int par , int dep) {
    int rem = k - 1 - (dep >= 1);
    for (int i = 0 ;i < adj[node].size() ;i++) {
        int child = adj[node][i];
        if (child == par) continue;
        mul(rem--);
    }

    for (int c : adj[node])
        if (c != par)
            solve(c , node , dep + 1);
}

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    cin >> n >> k;

    for (int i = 0 ;i < n - 1 ;i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = k;
    solve(1 , -1 , 0);
    cout << ans;
}