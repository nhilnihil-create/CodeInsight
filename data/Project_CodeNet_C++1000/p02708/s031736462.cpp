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

  ll n, k;
  cin >> n >> k;
  ll minv = k * (k - 1) / 2;
  ll maxv = 0;
  rep(i, 0, k) { maxv += n - i; }

  ll ans = maxv - minv + 1;
  ans %= MOD;
  rep(i, k, n + 1) {
    minv += i;
    maxv += n - i;
    ans += maxv - minv + 1;
    ans %= MOD;
  }

  cout << ans << endl;
}
