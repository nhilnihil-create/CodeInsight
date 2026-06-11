#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

vector<ll> ans;
vector<ll> memo;

void dfs(const vector<vector<int>> &G, int v, int p){
  if(v==0){
    ans[v]=memo[v];
  }
  else{
    ans[v]=memo[v]+ans[p];
  }
  for(auto nv:G[v]){
    if(nv==p) continue;
    dfs(G,nv,v);
  }
}

int main() {
  int n,q;
  cin>>n>>q;
  vector<vector<int>> G(n);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  memo.assign(n,0);
  for(int i=0;i<q;i++){
    int p,x;
    cin>>p>>x;
    p--;
    memo[p]+=x;
  }
  ans.assign(n,0);
  dfs(G,0,-1);
  for(int i=0;i<n;i++){
    cout<<ans[i];
    if(i!=n-1) cout<<' ';
  }
  cout<<endl;
  return 0;
}
