#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll f[10000002];

int main() {

  ll n; cin >> n;
  for (int i = 1; i < 10000002; ++i) {
      for (int j = i; j < 10000002; j+=i) {
        ++f[j];
      }
   }

  ll ans = 0;
  for(ll i = 1; i <= n; ++i){
    ans += (i * f[i]);
  }
  cout << ans;
  return 0;
}
