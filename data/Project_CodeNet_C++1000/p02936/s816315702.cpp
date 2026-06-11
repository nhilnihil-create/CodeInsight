#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//解説AC
int n,q;
vector<int>G[201010];

void dfs(int v,int p,vector<long long> &a){
  if(p!=-1)a[v]+=a[p];
  rep(i,G[v].size()){
    int e=G[v][i];
    if(e==p)continue;
    dfs(e,v,a);
  }
}

int main(){
  cin>>n>>q;
  rep(i,n-1){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<long long>a(n,0);
  rep(i,q){
    int x,y;
    cin>>x>>y;
    x--;
    a[x]+=y;
  }
  dfs(0,-1,a);
  rep(i,n)cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}