#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> v(n), a(n + 1, 0);
  rep(i, 0, n) {
    cin >> v[i];
    a[v[i]]++;
  }

  ll all = 0;
  rep(i, 1, n + 1) { all += (a[i] * (a[i] - 1)) / 2; }

  rep(i, 0, n) {
    ll ans = 0;
    ll t1 = a[v[i]];
    ll t2 = a[v[i]] - 1;
    ans = all - ((t1 * (t1 - 1)) / 2 - (t2 * (t2 - 1)) / 2);
    cout << ans << endl;
  }
}
