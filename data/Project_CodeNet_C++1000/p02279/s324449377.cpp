#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 100000
vector<int> G[MAX];
int id[MAX],pa[MAX],dp[MAX],used[MAX];
void dfs(int v,int d){
  dp[v]=d;
  for(int i=0;i<(int)G[v].size();i++){
    dfs(G[v][i],d+1);
    pa[G[v][i]]=v;
  }
}
signed main(){
  int n;
  cin>>n;
  for(int i=0,k;i<n;i++){
    cin>>id[i]>>k;
    G[id[i]].resize(k);
    for(int j=0;j<k;j++){
      cin>>G[id[i]][j];
      used[G[id[i]][j]]=1;
    }
  }
  memset(pa,-1,sizeof(pa));
  for(int i=0;i<n;i++){
    if(!used[i]) dfs(i,0);
  }
  for(int i=0;i<n;i++){
    cout<<"node "<<i<<": parent = "<<pa[i]<<", depth = "<<dp[i];
    if(pa[i]<0) cout<<", root, [";
    else if(!G[i].size()) cout<<", leaf, [";
    else cout<<", internal node, [";
    for(int j=0;j<(int)G[i].size();j++){
      if(j) cout<<", ";
      cout<<G[i][j];
    }
    cout<<"]"<<endl;
  }
  return 0;
}