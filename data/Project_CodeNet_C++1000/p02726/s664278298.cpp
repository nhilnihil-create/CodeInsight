#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        adj[i].push_back(i + 1);
        adj[i + 1].push_back(i);
    }
    adj[a].push_back(b);
    adj[b].push_back(a);
    vector<int> kek(n);

    for (int i = 1; i <= n; i++) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int k : adj[v]) {
                if (dist[k] == -1) {
                    dist[k] = dist[v] + 1;
                    q.push(k);
                }
            }
        }
        for (int k : dist) {
            if (k == -1) continue;
            kek[k]++;
        }
    }

    for (int i = 1; i < n; i++) {
        cout << kek[i] / 2 << ' ';
    }
    cout << '\n';

    fflush(stdout);
    return 0;
}
