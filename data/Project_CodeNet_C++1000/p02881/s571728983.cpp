#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n;
  cin >> n;
  ll ans = 1000000000000;
  for (ll i = 1; i*i <= n; i++) {
    ll j = n/i;
    if (i*j == n) {
      ans = min(ans, i+j-2);
    }
  }
  cout << ans << endl;
  return 0;
}
