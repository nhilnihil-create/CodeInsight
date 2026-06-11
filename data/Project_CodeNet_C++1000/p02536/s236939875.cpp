#include<bits/stdc++.h>
using namespace std;


void dfs(int u,vector<vector<int>>&g,vector<bool> &vis){
 
 vis[u]=1;
 for(auto v:g[u]){
      
        if(vis[v]==0){
        dfs(v,g,vis);
        }
 }

}

int main()
{

    int count=0;
int n,m;
cin>>n>>m;

vector<vector<int>> g(n+1);
vector<bool> vis(n+1,false);

for(int i=0;i<m;i++){

int a,b;
cin>>a>>b;
g[a].push_back(b);
g[b].push_back(a);

}


for(int i=1;i<=n;i++){

  if(vis[i]==false){
     
    dfs(i,g,vis);
    count++;
}
}
cout<<count-1<<endl;

}
