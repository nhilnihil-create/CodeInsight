#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using int64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> cnt(10, vector<int>(10));
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    int firs = s[0] - '0', last = s.back() - '0';
    ++cnt[firs][last];
  }
  int ans = 0;
  rep(i, 10) {
    rep(j, 10) {
      ans += cnt[i][j] * cnt[j][i];
    }
  }
  cout << ans;
  return 0;
}