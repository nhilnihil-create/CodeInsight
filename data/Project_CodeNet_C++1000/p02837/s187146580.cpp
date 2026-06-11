#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<vector<int>> vec(n,vector<int>(n,-1));
  rep(i,n){
    int a;cin>>a;
    rep(j,a){
      int x,y;cin>>x>>y;
      x--;
      vec[i][x]=y;
    }
  }
  int ans=0;
  rep(bit,1<<n){
    vector<int> d(n);
    rep(i,n)if(bit&(1<<i))d[i]=1;
    bool ok=true;
    rep(i,n)if(bit&(1<<i)){
      rep(j,n){
        if(vec[i][j]==-1)continue;
        if(vec[i][j]!=d[j])ok=false;
      }
    }
    if(ok)ans=max(ans,__builtin_popcount(bit));
  }
  cout<<ans<<endl;
}