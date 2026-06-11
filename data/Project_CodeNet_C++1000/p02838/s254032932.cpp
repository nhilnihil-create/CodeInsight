#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n;
  cin >> n;
  vector<ll> A(n);
  for (auto& _a : A) cin >> _a;
  ll ans = 0;
  for (ll b = 0; b < 62; ++b) {
    ll n1 = 0;
    for (ll i = 0; i < n; ++i) {
      ll n0 = i - n1;
      if (A[i] >> b & 1) {
        ans += (n0 * ((1LL << b) % mod))%mod;
        ++n1;
      } else {
        ans += (n1 * ((1LL << b) % mod))%mod;
      }
      ans %= mod;
    }
  }
  ans %= mod;
  cout << ans << endl;
}
