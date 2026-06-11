#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {

  ll n; cin >> n;
  ll ans = 0;
  for(ll i = 2; i * i <= n; ++i){
    ll cnt = 0;
    ll kanta = 1;
    while(n % i == 0){
        n = n / i;
        cnt++;
        if(cnt >= kanta){
            cnt = 0;
            kanta++;
            ans++;
        }
    }
  }
  if(n != 1)ans++;
  cout << ans;
  return 0;
}
