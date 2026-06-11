#include <bits/stdc++.h>
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1000000007LL;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
int main() {
  IOS;
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = (bpow(2, n) - 1 + MOD) % MOD;
  ll x = 1, y = 1;
  for (ll i = 1; i <= b; i++) {
    x = x * (n - i + 1) % MOD, y = y * i % MOD;
    if (i == a || i == b) {
      ans = (ans - x * bpow(y, MOD - 2) % MOD + MOD) % MOD;
    }
  }
  cout << ans << endl;
}
