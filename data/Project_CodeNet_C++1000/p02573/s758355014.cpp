#include<bits/stdc++.h>
using namespace std;
int n,m,ans,sz;
vector<int> g[200005];
bool vis[200005];
void dfs(int x){
    vis[x]=1;
    sz++;
    for(int &y:g[x])if(!vis[y]){
        dfs(y);
    }
}
signed main(void){
	cin>>n>>m;
    for(int i=1;i<=m;i++){
        static int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i=1;i<=n;i++)if(!vis[i]){
        sz=0;
        dfs(i);
        ans=max(ans,sz);
    }
    cout<<ans<<endl;
	return 0;
}