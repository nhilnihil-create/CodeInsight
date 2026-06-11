#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> G[200020];
vector<ll> P(200020),A(200020);
vector<ll> par(200020,-1);

void dfs(int u){
  A[u]=P[u]+A[par[u]];
  for(auto x:G[u]){
    if(par[x]!=-1) continue;
    par[x]=u;
    dfs(x);
  }
}

int main() {
  int q;
  cin>>n>>q;
  
  par[0]=0;

  int a,b;
  rep(i,n-1){
    cin>>a>>b;
    a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  ll p,x;
  rep(i,q){
    cin>>p>>x;
    p--;
    P[p]+=x;
  }
  
  dfs(0);
  
  rep(i,n){
    if(i) cout<<" ";
    cout<<A[i];
  }
  cout<<endl;
  
  return 0;
}