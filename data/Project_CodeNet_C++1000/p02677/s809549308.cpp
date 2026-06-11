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

  int a, b, h, m;
  cin >> a >> b >> h >> m;

  double sho = h * 30 + 0.5 * m;
  double lon = 6 * m;
  double kakudo = sho - lon;

  double ans = a * a + b * b - 2 * a * b * cos(M_PI / 180 * kakudo);
  cout << fixed << setprecision(12) << sqrt(ans) << endl;
}
