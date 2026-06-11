#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll total = 0;
  rep(i, n) total += a[i];
  set<ll> candidate;
  for (int i = 1; i*i <= total; i++) {
    if (total % i == 0) {
      candidate.insert(i);
      candidate.insert(total/i);
    }
  }
  ll ans = 1;
  for (ll d : candidate) {
    vector<ll> r(n);
    rep(i, n) r[i] = a[i] % d;
    sort(r.begin(), r.end());
    ll B = 0;
    rep(i, n) B += d - r[i];
    ll A = 0;
    ll need = 1e18;
    rep(i, n) {
      A += r[i];
      B -= d - r[i];
      need = min(need, max(A, B));
    }
    if (need <= k) {
      ans = max(ans, d);
    }
  }
  cout << ans << '\n';
  return 0;
}