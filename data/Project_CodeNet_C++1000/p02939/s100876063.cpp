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

  string s;
  cin >> s;
  int n = s.size();

  int ans = 1;
  bool flg = false;
  rep(i, 1, n) {
    ans++;
    if (!flg && s[i] == s[i - 1]) {
      i++;
      flg = true;
      if (i == n)
        ans--;
    } else {
      flg = false;
    }
  }

  cout << ans << endl;
}
