#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>G;
vector<bool>seen;
vector<int> cost;
void dfs(int v,int p=-1){
  seen[v]=true;
  if(v!=0)cost[v]+=cost[p];
  for(auto next_v:G[v]){
    if(next_v==p)continue;
    if(seen[next_v])continue;
    dfs(next_v,v);
  }
}
int main(){
  int n,q;
  cin>>n>>q;
  G.resize(n);
  cost.assign(n,0);
  seen.assign(n,false);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;
    a--;
    cost[a]+=b;
  }
  for(int i=0;i<n;i++){
    if(seen[i])continue;
    dfs(i);
  }
for(int i=0;i<n;i++){
  cout<<cost[i]<<" ";
}
cout<<endl;
}