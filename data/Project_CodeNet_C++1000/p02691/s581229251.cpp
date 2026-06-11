#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n; cin >> n;
  map<ll, ll> mp;
  ll ans=0;
  for (ll i=1; i<=n; i++) {
    ll h; cin >> h;
    ans += mp[i-h];
    mp[i+h]++;
  }
  cout << ans;
  return 0;
}
