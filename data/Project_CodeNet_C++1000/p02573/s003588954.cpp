#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define oo 100000000000000000
using namespace std;

set<int> g[200200];
vector<bool> vis;

int dfs(int node, int par){
    int cnt = 1;
    vis[node] = 1;
    for(auto &i: g[node]){
        if(!vis[i] && i!=par){
            cnt+= dfs(i,node);
        }
    }
    return cnt;
}

void _sol(){
    int n,m; cin >> n >> m;
    vis.assign(n+1,0);
    forr(i,m){
        int u,v; cin >> u >> v;
        g[u].insert(v); g[v].insert(u);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]) ans = max(ans , dfs(i,-1));
    }
    cout << ans;

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    _sol();
}
