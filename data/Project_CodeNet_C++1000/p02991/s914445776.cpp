#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    int s, t;
    cin >> s >> t;
    s--; t--;

    vector<vector<int>> dist(n, vector<int>(3, INF));
    queue<P> que;

    que.push(P(s,0));
    dist[s][0] = 0;

    while(!que.empty()){
        int v = que.front().first;
        int l = que.front().second;
        que.pop();
        for(int u : g[v]){
            int nl = (l+1)%3;
            if(dist[u][nl] != INF) continue;
            dist[u][nl] = dist[v][l] + 1;
            que.push(P(u,nl));
        }
    }
    int ans = dist[t][0];
    if(ans == INF) ans = -1;
    else ans /= 3;
    cout << ans << endl;
}