#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using VP = vector<P>;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

vector<bool> isPrime;
void f1(ll n) {
  isPrime.resize(n + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (ll i = 2; i * i <= n; ++i)
    if (isPrime[i])
      for (ll j = 2; i * j <= n; ++j) isPrime[i * j] = false;
}

VP f2(ll N) {
  VP v;
  rep(i, 0, isPrime.size()) {
    if (!isPrime[i]) continue;
    if (N % i != 0) continue;
    ll exp = 0;
    while (N % i == 0) {
      ++exp;
      N /= i;
    }
    v.emplace_back(i, exp);
  }
  if (N != 1) v.emplace_back(N, 1);
  return v;
}

void solve() {
  ll n, ans = 0;
  cin >> n;

  f1(sqrt(n));
  VP v = f2(n);

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