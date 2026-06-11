#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string s, t;
  cin >> s >> t;

  int ans = t.size();
  for (int i = 0; i + t.size() <= (int)s.size(); ++i) {
    int cur = 0;
    for (int j = 0; j < (int)t.size(); ++j) {
      if (s[i+j] != t[j]) ++cur;
    }
    ans = min(ans, cur);
  }
  cout << ans << '\n';
}
