#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int ans = 0, n = s.size();
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j + 1 < n && s[j + 1] == s[j]) {
      ++j;
    }
    ans += (j - i + 1) / 3 * 2 + (bool)((j - i + 1) % 3) + ((j - i + 1) % 3 == 2 && j != n - 1);
    i = j + ((j - i + 1) % 3 == 2);
  }
  cout << ans << '\n';
  return 0;
}
