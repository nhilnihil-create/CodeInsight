#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=2e5+9;

vector<int>adj[N];
int n,m;
bool vis[N];
void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v]==1) continue;
        dfs(v);
    }
}

int main(){

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
            ans++;
        }
    }
    cout<<max(0LL,ans-1)<<endl;

}






