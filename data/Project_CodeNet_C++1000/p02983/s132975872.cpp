#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, s, n) for(ll i = s; i < n; i++)
using namespace std;

const ll mod = 2019;
int main(){
  ll L, R;
  cin >> L >> R;
  if (R - L >= 2019) cout << 0 << endl;
  else{
    ll ans = mod;
    rep2(i, L, R)rep2(j, i+1, R+1){
      ans = min(ans, i * j % mod);
    }
    cout << ans << endl;
  }
  
  return 0;
}