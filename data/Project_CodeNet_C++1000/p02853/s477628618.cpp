#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int solve(int v) {
  if (v == 1)
    return 300000;
  else if (v == 2)
    return 200000;
  else if (v == 3)
    return 100000;
  else
    return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x, y;
  cin >> x >> y;

  int ans = solve(x);
  ans += solve(y);
  if (x == 1 && y == 1)
    ans += 400000;
  cout << ans << endl;
}
