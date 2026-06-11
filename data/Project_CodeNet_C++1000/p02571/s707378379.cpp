																																																																																																						#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int, int>;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(NULL);

  string s, t;

  cin >> s >> t;

  int ans = INT_MAX;
  for (int i = 0; i < s.length() - t.length() + 1; i++) {
    int cnt = 0;

    for (int j = 0; j < t.length(); j++)
      cnt += s[i + j] != t[j];

    ans = min(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}
