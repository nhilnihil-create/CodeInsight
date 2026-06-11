#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    string ss;
    cin >> ss;
    sort(ss.begin(), ss.end());
    s[i] = ss;
  }
  sort(s.begin(), s.end());
  ll ans = 0, cnt = 1;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      cnt++;
      if (i == n - 2) {
        ans += cnt * (cnt - 1) / 2;
      }
    } else {
      ans += cnt * (cnt - 1) / 2;
      cnt = 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
