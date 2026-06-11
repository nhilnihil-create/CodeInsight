#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for ( int i=0; i<m; i++ ) {
        int u,v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    }
    int s,t;
    cin >> s >> t;
    --s; --t;
    vector<vector<int>> dist(n, vector<int>(3,INF));
    dist[s][0]=0;
    vector<int> q;
    q.push_back(s);
    while ( q.size() ) {
        vector<int> nq;
        for ( int x:q ) {
            int k=x/n;
            int v=x%n;
            int nk=(k+1)%3;
            for ( int u:g[v] ) {
                if ( dist[u][nk]>dist[v][k]+1 ) {
                    dist[u][nk] = dist[v][k]+1;
                    nq.push_back(n*nk+u);
                }
            }
        }
        q=nq;
    }
    if ( dist[t][0]<INF ) cout << dist[t][0]/3 << '\n';
    else cout << -1 << '\n';
    return 0;
}