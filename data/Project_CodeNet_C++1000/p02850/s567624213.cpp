#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5; 
vector<array<int,2> > adj[N]; 
vector<int> ans(N,0); 
void dfs(int u,int p,int prev,int mx){
for(auto& i: adj[u]){
if(i[0]!=p){
prev=(prev%mx)+1; 
ans[i[1]]=prev; 
dfs(i[0],u,ans[i[1]],mx); 
}
}
}
int main(){
int n; cin>>n;
int u,v; 
for(int i=0;i<n-1;i++){ cin>>u>>v; adj[u].push_back({v,i}); adj[v].push_back({u,i}); }
int mx=0; 
for(int i=1;i<=n;i++) mx=max(mx,(int)adj[i].size()); 
dfs(1,0,0,mx);
cout<<mx<<endl; 
for(int i=0;i<n-1;i++) cout<< ans[i]<<endl ;
return 0; 
}