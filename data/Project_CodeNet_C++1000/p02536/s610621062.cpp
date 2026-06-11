#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int vis[N];
vector<int>G[N];
void dfs(int n){
    vis[n]=1;
    for(auto i:G[n]) {
    if(!vis[i]) dfs(i);
    }
}

int main(){
    int n,M,ans=0;cin>>n>>M;
    while(M--){
        int u,v;cin>>u>>v;

    G[u].push_back(v);
    G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        if (!vis[i]) {
            ans++;
        dfs(i);
    }
    }
    cout<<ans-1;
    return 0;
}
