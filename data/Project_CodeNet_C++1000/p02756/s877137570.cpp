#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int q;
  cin >> s >> q;
  bool r = false;
  string beg, end;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      r = !r;
    } else {
      int f;
      char c;
      cin >> f >> c;
      f--;
      if (f ^ r) {
        end += c;
      } else {
        beg += c;
      }
    }
  }
  reverse(beg.begin(), beg.end());
  string ans = beg;
  for (auto&& c : s) {
    ans += c;
  }
  for (auto&& c : end) {
    ans += c;
  }
  if (r) reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}
