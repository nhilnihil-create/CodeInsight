#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int h,w,k;cin>>h>>w>>k;
  vector<vector<char>> c(h,vector<char>(w));
  rep(i,h)rep(j,w)cin>>c[i][j];
  int ans=0;
  rep(bit1,1<<h)rep(bit2,1<<w){
    vector<int> H(h),W(w);
    rep(i,h)rep(j,w){
      if(bit1&(1<<i)){
        if(c[i][j]=='#')H[i]=1;
      }
      if(bit2&(1<<j)){
        if(c[i][j]=='#')W[j]=1;
      }
    }
    int cnt=0;
    rep(i,h){
      if(H[i]==1)continue;
      rep(j,w){
        if(W[j]==0){
          if(c[i][j]=='#')cnt++;
        }
      }
    }
    if(cnt==k)ans++;
  }
  cout<<ans<<endl;
}