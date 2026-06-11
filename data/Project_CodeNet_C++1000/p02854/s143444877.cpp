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
  vector<ll> acc(n + 1, 0);
  rep(i, 0, n) {
    int a;
    cin >> a;
    acc[i + 1] = acc[i] + a;
  }

  ll ans = 1e18;
  rep(i, 1, n) { chmin(ans, abs(acc[i] - (acc[n] - acc[i]))); }
  cout << ans << endl;
}
