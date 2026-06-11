#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
const ll INF = 1e15;

ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> d(n);
  map<ll, ll> mp;
  REP(i, n) {
    cin >> d[i];
    mp[d[i]]++;
  }

  ll mx = mp.size();
  if (!(mp[0] == 1 && d[0] == 0)) {
    cout << 0 << endl;
    return 0;
  }
  REP(i, mx) {
    if (mp[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = 1;
  const ll MOD = 998244353;
  FOR(i, 1, mx) {
    ans *= mod_pow(mp[i - 1], mp[i], MOD);
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}