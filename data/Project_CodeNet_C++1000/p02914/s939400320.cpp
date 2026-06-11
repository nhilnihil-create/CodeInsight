#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

ll check_bit(ll x, int i) { return (x & (1LL << i)); }

vector<ll> v;
ll gaussian_elimination() {
  int n = v.size();
  int ind = 0; // Array index
  for (int bit = 60; bit >= 0; bit--) {
  // for (int bit = log2(v[0]); bit >= 0; bit--) {
    int x = ind;
    while (x < n && check_bit(v[x], bit) == 0) x++;
    if (x == n) continue; // skip if there is no number below ind where current bit is 1
    swap(v[ind], v[x]);
    for (int j = 0; j < n; j++) {
      if (j != ind && check_bit(v[j], bit)) v[j] ^= v[ind];
    }
    ind++;
  }
  ll ans = v[0];
  for (int i = 1; i < n; i++) ans = max(ans, ans ^ v[i]);
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll x = 0;
  rep(i, n) x ^= a[i];
  dump(a);
  ll ans = x;
  dump(x);
  rep(i, n) a[i] &= ~x;
  rep(i, n) v.push_back(a[i]);
  ll m = gaussian_elimination();
  dump(a);
  dump(v);
  dump(m);
  ans += m * 2;
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}