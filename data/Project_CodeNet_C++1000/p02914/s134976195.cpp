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

// ガウス除去法 (xor)
ll GaussElimination(vl& v) {
  int n = v.size();
  int idx = 0;
  for (int b = 60; 0 <= b; b--) {
    int x = idx;
    while (x < n && ((v[x] >> b) & 1) == 0) x++;
    if (x == n) continue; // もしbitが1の要素がなければスキップ
    swap(v[idx], v[x]);
    rep(i, n) if ((i != idx) && (((v[i] >> b) & 1) == 1)) v[i] ^= v[idx];
    idx++;
  }
  // 部分集合の最大xor値を返す
  ll mx = 0;
  rep(i, n) mx ^= v[i];
  return mx;
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
  vl v;
  rep(i, n) v.push_back(a[i]);
  ll m = GaussElimination(v);
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