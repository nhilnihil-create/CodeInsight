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

  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int mm1 = h1 * 60 + m1;
  int mm2 = h2 * 60 + m2;
  int ans = mm2 - mm1 - k;
  cout << max(0, ans) << endl;
}
