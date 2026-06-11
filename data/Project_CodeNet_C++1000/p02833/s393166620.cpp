#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  ll n; cin >> n;
  if(n == 0){
    cout << 0 << endl;
    return 0;
  }
  if(n % 2 == 1){
    cout << 0 << endl;
    return 0;
  }
  /*ll sum = 0;
  for(ll i = 0; i <= n; i++){
    ll x = i, cnt = 0;
    while(x > 0 && x % 10 == 0){
      cnt++;
      x /= 10;
    }
    sum += cnt;
  }
  cout << sum << endl;*/
  ll ans = 0;
  for(ll i = 10; i <= n; i *= 5){
    ans = ans + n / i;
  }
  cout << ans << endl;

  return 0;
}
