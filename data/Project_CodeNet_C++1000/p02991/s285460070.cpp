#include<bits/stdc++.h>
using namespace std;

const int INF = 1001001001;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n), dist(n, vector<int>(3, INF));
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        to[u].push_back(v);
    }
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    queue<pair<int, int>> q;
    q.push({s, 0});
    dist[s][0] = 0;
    while(!q.empty()) {
        int u = q.front().first;
        int l = q.front().second;
        q.pop();
        for(auto&& v : to[u]) {
            int nl = (l + 1) % 3;
            if(dist[v][nl] != INF) continue;
            dist[v][nl] = dist[u][l] + 1;
            q.push({v, nl});
        }
    }
    if(dist[t][0] == INF) cout << -1 << endl;
    else cout << dist[t][0] / 3 << endl;
}
