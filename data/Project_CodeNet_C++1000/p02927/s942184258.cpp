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

  int m, d;
  cin >> m >> d;

  int ans = 0;
  rep(i, 1, m + 1) {
    rep(j, 1, d + 1) {
      int d1 = j % 10;
      int d2 = (j / 10) % 10;
      if (d1 >= 2 && d2 >= 2 && d1 * d2 == i)
        ans++;
    }
  }

  cout << ans << endl;
}
