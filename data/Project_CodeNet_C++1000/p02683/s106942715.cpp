#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,m,x;cin>>n>>m>>x;
  vector<int> c(n);
  vector<vector<int>> a(n,vector<int>(m));
  rep(i,n){
    cin>>c[i];
    rep(j,m)cin>>a[i][j];
  }
  int ans=1e9;
  bool ok1=false;
  rep(bit,1<<n){
    bool ok=true;
    int cnt=0;
    vector<int> vec(m);
    rep(i,n){
    if(bit&(1<<i)){
      cnt+=c[i];
      rep(j,m){
        vec[j]+=a[i][j];
      }
    }
    }
    rep(i,m){
      if(vec[i]<x)ok=false;
    }
    if(ok){
      ans=min(ans,cnt);
      ok1=true;
    }
  }
  if(ok1)cout<<ans<<endl;
  else cout<<-1<<endl;
}