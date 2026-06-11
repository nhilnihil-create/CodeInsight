#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n,m,x;
  cin >> n>>m>>x;
  int a[n][m];
  int c[n];
  rep(i,n+1){
    cin >> c[i];
    rep(j,m){
      cin >> a[i][j];
    }
  }
      
  int ans=1e9;
  for(int bit=0;bit<(1<<n);bit++){
    vector<int> is(m,0);
    int mini=0;
    rep(i,n){
      if(bit>>i&1){
        mini+=c[i];
        rep(j,m){
          is.at(j)+=a[i][j];
        }
      }
    }
    bool isno=true;
    rep(i,m){
      if(x>is.at(i)){
        isno=false;
      }
    }
    if(isno){
      ans=min(ans,mini);
    }
  }
  if(ans==1e9){
    ans=-1;
  }
  cout <<ans;
}
          