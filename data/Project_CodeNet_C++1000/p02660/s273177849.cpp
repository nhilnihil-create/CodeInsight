#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using VP = vector<P>;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

VP f(ll N) {
  VP v;
  for (ll a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    ll exp = 0;
    while (N % a == 0) {
      ++exp;
      N /= a;
    }
    v.emplace_back(a, exp);
  }
  if (N != 1) v.emplace_back(N, 1);
  return v;
}

void solve() {
  ll n, ans = 0;
  cin >> n;
  VP v = f(n);
  if (v.size() == 0) {
    cout << 0 << endl;
    return;
  }
  for (const auto &p : v) {
    ll x = p.second;
    ll i = 1;
    while (x >= i) {
      ans++;
      x -= i++;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}