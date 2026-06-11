#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  ll n, d;cin>>n>>d;
  ll cnt=0;
  
  ll a[n][d];
  rep(i, n){
    rep(j, d) cin>>a[i][j];
  }
  rep(i, n){
    for(ll j=i+1; j<n; j++) {
      ll s=0;
      rep(k, d) {
        s+=(a[i][k]-a[j][k])*(a[i][k]-a[j][k]);
      }
      if(sqrt(s)==floor(sqrt(s))) cnt++;
    }
  }
  cout << cnt;
}
      