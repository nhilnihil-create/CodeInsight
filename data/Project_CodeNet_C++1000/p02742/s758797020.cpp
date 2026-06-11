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

  ll H, W;
  cin >> H >> W;
  if (H == 1 || W == 1)
    cout << 1 << endl;
  else {
    ll ro = (H + 1) / 2;
    ll re = H - ro;
    ll ans = (ro * ((W + 1) / 2)) + (re * (W / 2));
    cout << ans << endl;
  }
}
