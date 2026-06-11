#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9;
vector<int>g[N];
int n,m,ans,vis[N];

void dfs(int n){ 
    vis[n]=1;
    for(int i=0;i<g[n].size();i++){ 
        if(vis[g[n][i]]==0)dfs(g[n][i]);
    } 
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin>>n>>m;
    for(int x,y,i=0;i<m;i++){ 
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    } 
    for(int i=1;i<=n;i++){ 
        if(vis[i]==0){ 
            ans++;
            dfs(i);
        } 
    }
    cout<<ans-1<<endl; 

    return 0;
}
