#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(3*n);
    int s,t;
    for(int i = 0; i < m; i++) {
        cin >> s >> t;
        s--;
        t--;
        g[s*3].emplace_back(t*3+1);
        g[s*3+1].emplace_back(t*3+2);
        g[s*3+2].emplace_back(t*3);
    }
    cin >> s >> t;
    s=(s-1)*3;
    t=(t-1)*3;

    vector<int> dist(n*3,-1);
    dist[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int v=q.front();
        int d=dist[v];
        q.pop();
        for(auto &nv : g[v]) {
            if(dist[nv]!=-1) continue;
            dist[nv]=d+1;
            q.push(nv);
        }
    }
    if(dist[t]==-1) cout << "-1" << "\n";
    else cout << dist[t]/3 << "\n";

    return 0;
}