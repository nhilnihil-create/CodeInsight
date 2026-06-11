#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define chmax(x, v)                                                            \
  do {                                                                         \
    x = max(x, v);                                                             \
  } while (0)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  ll n,ans=0;
  cin >> n;
  if (n==1) {
    cout << 0 << endl;
    return 0;
  }
  if (n==2) {
    cout << 1 << endl;
    return 0;
  }
  for (ll i = 1; i <= n/2; i++) {
    ll j = n-i;
    if (j!=i)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
