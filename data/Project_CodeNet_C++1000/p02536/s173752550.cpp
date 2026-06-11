#include <bits/stdc++.h> 
using namespace std;  
#define ll long long int
vector<ll>adj[100005];
vector<ll>vis(100005,false);

void dfs(ll i)
{   
  if(!vis[i]){
    vis[i]=true;
    for(auto it:adj[i])
       dfs(it); 
  }  
}   
int main() 
{ 
        // ll t;
        // cin>>t;
        // while(t--){ 
        ll n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);  
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
             cnt++;
             dfs(i);   
        }
        cout<<cnt-1;
    }

   
   