#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

vector<int> edges[300005];

bool vis[300005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(n + v);
        edges[n + u].push_back(2 * n + v);
        edges[2 * n + u].push_back(v);
    }
    int s, t;
    cin >> s >> t;
    queue<int> q;
    vis[s] = true;
    q.push(s);
    int layer = -1;
    bool ok = false;
    while (!q.empty() && !ok) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            int cur = q.front(); q.pop();
            if (cur == t) { ok = true; break; }
            for (int nxt : edges[cur]) {
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        layer++;
    }
    if (ok) {
        cout << layer / 3 << endl;
    } else {
        cout << -1 << endl;
    }
}
