#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

ll MOD = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<ll>a(n);
  rep(i,0,n) cin >> a[i];
  vector<ll>cnt0(61);
  vector<ll>cnt1(61);
  rep(i,0,n){
    for(int bit = 0; bit < 61;++bit){
      if(a[i]&(1LL<<bit)) cnt1[bit]++;
      else cnt0[bit]++;
    }
  }
  ll ans = 0;
  ll c = 1;
  rep(i,0,61){
    ll tmp = (cnt0[i]*cnt1[i])%MOD*c%MOD;
    ans = (ans+tmp)%MOD;
    c = (c*2)%MOD;
  }
  cout << ans << endl;
}