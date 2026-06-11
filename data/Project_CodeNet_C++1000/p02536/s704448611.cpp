#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n)for(int i=0;i<(int)(n);i++)
using namespace std;
using Graph=vector<vector<int>>;
using p=pair<long,long>;

vector<bool> visited;

void dfs(const Graph &g, int root){
  visited[root]=true;
  for(int nv:g[root]){
    if(!visited[nv])dfs(g,nv);
  }
}

int main() {

  int n,m;
  cin>>n>>m;
  Graph g(n);
  
  rep(i,m){
    int start,goal;
    cin>>start>>goal;
    start-=1;goal-=1;

    g[start].emplace_back(goal);
    g[goal].emplace_back(start);
  }

  visited.assign(n,false);
  int ans=0;

  for(int i=0;i<n;i++){
    if(!visited[i]){
      dfs(g,i);
      ans+=1;
    }
  }

  cout<<ans-1<<endl;
  return 0;
}
