#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
vector<int> adj[100005];
bool vis[100005];
void dfs(int s){
    vis[s] = true;
    for(int i=0;i<adj[s].size();++i){
        if(!vis[adj[s][i]]) dfs(adj[s][i]);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    for(int i=1;i<=n;++i) if(!vis[i]) dfs(i),ans++;
    cout<<ans-1;
}
