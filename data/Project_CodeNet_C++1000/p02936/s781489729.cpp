#include <bits/stdc++.h>

typedef long long ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl '\n'
const int N = 2e5 + 10;
using namespace std;
int sum[N] = {};
vector<vector<int>> adj;

void dfs(int u, int p) {
    for (auto child:adj[u]) {
        if (child != p) {
            sum[child] += sum[u];
            dfs(child, u);
        }
    }
}

int main() {
    IO;
    int n, t;
    cin >> n >> t;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while (t--) {
        int u, x;
        cin >> u >> x;
        sum[u] += x;
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        cout << sum[i] << " ";
    }


}
