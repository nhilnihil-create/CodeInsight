#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  rep(_, n) {
    s.push_back('x');
  }
  vector<int> cnt_r(n, 0), cnt_g(n, 0), cnt_b(n, 0);
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      cnt_r[i] = cnt_r[i - 1];
      cnt_g[i] = cnt_g[i - 1];
      cnt_b[i] = cnt_b[i - 1];
    }
    if (s[i] == 'R') {
      cnt_r[i]++;
    } else if (s[i] == 'G') {
      cnt_g[i]++;
    } else {
      cnt_b[i]++;
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (s[i] == s[j]) continue;
      map<char, int> mp;
      mp[s[i]]++, mp[s[j]]++;
      if (mp['R'] == 0) {
        ans += cnt_r[n - 1] - cnt_r[j];
        if (s[2 * j - i] == 'R') {
          ans--;
        }
      } else if (mp['G'] == 0) {
        ans += cnt_g[n - 1] - cnt_g[j];
        if (s[2 * j - i] == 'G') {
          ans--;
        }
      } else {
        ans += cnt_b[n - 1] - cnt_b[j];
        if (s[2 * j - i] == 'B') {
          ans--;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
