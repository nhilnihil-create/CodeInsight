#include<bits/stdc++.h>
using namespace std;

vector<int> g[100001];
bool vis[100001];

void dfs(int src)
{
  vis[src] = true;
  for(auto child:g[src]){
    if(!vis[child]){
      dfs(child);
    }
  }
}

int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  
  for(int i=1;i<=n;i++){
    vis[i]=false;
  }
  
  int cc=0;
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      dfs(i);
      cc++;
    }
  }
  cout<<cc-1<<endl;
}