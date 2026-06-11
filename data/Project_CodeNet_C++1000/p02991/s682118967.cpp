#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

using Graph = vector<vector<int>>;

int main(){
    int n, m; cin >> n >> m;
    Graph G(n);
    rep(i,m){
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
    }

    int s, t; cin >> s >> t; s--; t--;

    vector<vector<int>> dist(n, vector<int>(3,-1)); dist[s][0] = 0;
    queue<pair<int,int>> que; que.push(make_pair(s,0));
    while (!que.empty()) {
        pair<int,int> v = que.front();
        que.pop();
        for (int nv : G[v.first]) {
            if (dist[nv][(v.second+1)%3] != -1) continue;
            dist[nv][(v.second+1)%3] = v.second + 1;
            que.push(make_pair(nv, v.second + 1));
        }
    }

    if(dist[t][0] == -1) cout << -1 << endl;
    else cout << dist[t][0]/3 << endl;
}

