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

  double a, b, x;
  cin >> a >> b >> x;

  double s = x / a;
  double h = 0, ans = 0;
  if (s >= a * b / 2) {
    h = (a * b - s) * 2 / a;
    ans = atan2(h, a);
  } else {
    h = s * 2 / b;
    ans = atan2(b, h);
  }

  cout << fixed << setprecision(10) << ans * 360 / (2 * M_PI) << endl;
}
