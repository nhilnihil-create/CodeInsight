#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000, INF = 0x3f3f3f3f, M = 2e6 + 5;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define repe(i, u) for (int i = head[u]; i; i = nxt[i])

const double PI = M_PI;
int X[N], Y[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.precision(10);
  cout << fixed;
  double x, y, tx, ty;
  int n;
  cin >> n;
  rep(i, 1, n) cin >> X[i] >> Y[i];
  double ans = 0;
  rep(i, 0, 99) {
    x = cos(2 * PI * i / 100);
    y = sin(2 * PI * i / 100);
    tx = ty = 0;
    rep(j, 1, n) if (x * X[j] + y * Y[j] >= 0) tx += X[j], ty += Y[j];
    ans = max(ans, sqrt(tx * tx + ty * ty));
  }
  cout << ans << '\n';
}