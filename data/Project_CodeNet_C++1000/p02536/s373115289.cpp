#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> adj[100005];
map<ll,bool> visited;
void dfs(ll i,ll parent){
    if(!visited[i]){
        visited[i]=true;
        for(auto it: adj[i]){
            if(it!=parent)
                dfs(it,i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,m,i,x,y,ans=0;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>x>>y;
        x-=1;y-=1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,i);
            ans+=1;
        }
    }
    cout<<ans-1<<endl;
    return 0;
}

