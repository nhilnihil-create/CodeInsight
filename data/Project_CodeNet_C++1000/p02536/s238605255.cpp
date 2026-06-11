#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

void dfs(vector<int> adj[],vector<bool>&visi,int src){
    visi[src]=true;
    for(int i=0;i<adj[src].size();i++){
        if(visi[adj[src][i]]==false)
          dfs(adj,visi,adj[src][i]);
    }
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> adj[n+1];
  while(m--){
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
  }
  vector<bool> visi(n+1,false);
  int comp=0;
  for(int i=1;i<=n;i++){
      if(visi[i]==false){
          dfs(adj,visi,i);
          comp++;
      }
  }
  cout<<comp-1<<endl;
}