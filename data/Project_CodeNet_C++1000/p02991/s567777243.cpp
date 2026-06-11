#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> E(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        E[u].push_back(v);
    }
    int s, t;
    cin >> s >> t;
    s--; t--;
    vector<vector<int>> dist(n, vector<int>(3, INF));
    queue<P> q;
    q.push(make_pair(s, 0));
    dist[s][0] = 0;
    while (!q.empty()) {
        int u = q.front().first;
        int l = q.front().second;
        q.pop();
        int a = (l+1) % 3;
        for (int v: E[u]) {
            if (dist[v][a] != INF) continue;
            dist[v][a] = l+1;
            q.push(make_pair(v, l+1));
        }
    }
    int ans = dist[t][0];
    if (ans == INF) ans = -1;
    else ans /= 3;
    cout << ans << endl;
    return 0;
}