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
  vector<int> v(n);
  rep(i, 0, n) cin >> v[i];
  sort(v.begin(), v.end());

  int ans = 0;
  rep(i, 0, n) {
    rep(j, 0, i) {
      int ng = lower_bound(v.begin(), v.end(), v[i] + v[j]) - v.begin();
      int ok = i + 1;
      ans += ng - ok;
    }
  }

  cout << ans << endl;
}
