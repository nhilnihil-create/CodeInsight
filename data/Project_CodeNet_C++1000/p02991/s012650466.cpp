#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const int INF = 1001001001;

int main(){
    int n, m; cin >> n >> m;
    Graph G(n);
    rep(i, m){
        int u, v;
        cin >> u >> v; 
        --u , --v;
        G[u].pb(v);
    }
    int s, t; cin >> s >> t;
    --s, --t;
    vector<vector<int>> dist(n, vector<int>(3, -1));
    dist[s][0] = 0;
    //bfs
    queue<P> q;
    q.push(P(s, 0));
    while(!q.empty()){
        P now = q.front(); q.pop();
        int v = now.first;
        int p = now.second;
        for(auto nv : G[v]){
            int np = (p+1) % 3;
            if(dist[nv][np] == -1){
                dist[nv][np] = dist[v][p] + 1;
                q.push(P(nv, np));
            }
        }
    }
    if(dist[t][0] == -1) cout << -1 << endl;
    else cout << dist[t][0]/3 << endl;
    return 0;
}