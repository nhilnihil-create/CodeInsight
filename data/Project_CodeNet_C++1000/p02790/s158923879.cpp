#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll a,b;
  cin >> a >> b;
  ll ans = 0;
  
  if(a>b){
    ans = b;
  	rep(i, a-1){
      b *= 10;
      ans += b;
    }
  }
  else{
    ans = a;
    rep(i, b-1){
      a *= 10;
      ans += a;
    }
  }
  cout << ans << endl;
}