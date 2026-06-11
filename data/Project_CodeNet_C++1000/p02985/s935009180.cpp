#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MOD 1000000007

int main()
{
    int N, K; cin >> N >> K;
    vector<vector<int>> g(N+1);
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> c(N+1, -1);
    queue<int> q;
    q.push(1);
    c[1] = K;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        int colored = 1;
        for (int u : g[v]) {
            if (c[u] != -1) colored++;
        }
        for (int u : g[v]) {
            if (c[u] != -1) continue;
            q.push(u);
            c[u] = max(0, K-colored++);
        }
    }

    ll ans = 1;
    for (int i = 1; i <= N; i++) {
        ans = ans * c[i] % MOD;
    }
    cout << ans << endl;
}
