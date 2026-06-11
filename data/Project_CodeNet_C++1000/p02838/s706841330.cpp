#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];

  ll ans = 0;
  rep(i, 0, 60) {
    ll x = 0;
    rep(j, 0, n) if (a[j] >> i & 1) x++;
    ll now = x * (n - x) % MOD;
    rep(j, 0, i) now = now * 2 % MOD;
    ans += now;
    ans %= MOD;
  }
  cout << ans << endl;
}
