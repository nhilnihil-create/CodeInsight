#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n,m,x;
  cin >> n >> m >> x;
  int a[n][m];
  int c[n];
  rep(i,n){
    cin >> c[i];
    rep(j,m){
      cin >> a[i][j];
    }
  }
  int ans=1e9;
  for(int bit=0;bit<(1<<n);bit++){
    int mini=0;
    vector<int> is(m);
    rep(i,n){
      if(bit&(1<<i)){
        mini+=c[i];
        for(int j=0;j<m;j++){
          is.at(j)+=a[i][j];
        }
      }
    }
    bool pq=true;
    for(int j=0;j<m;j++){
      if(is.at(j)<x){
        pq=false;
      }
    }
    if(pq){
      ans=min(ans,mini);
    }
  }
  if(ans==1e9){
    ans=-1;
  }
  cout <<ans;
}