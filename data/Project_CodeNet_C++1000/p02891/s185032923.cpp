#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  long long k;
  cin >> k;
  int n = (int)s.size();
  if (s == string(n, s[0])) {
    cout << n * k / 2 << '\n';
    return 0;
  }
  long long cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      cnt++;
      i++;
    }
  }
  string ss = s + s;
  long long cnt2 = 0;
  for (int i = 0; i < 2 * n - 1; i++) {
    if (ss[i] == ss[i + 1]) {
      cnt2++;
      i++;
    }
  }
  cout << (cnt2 - cnt) * (k - 1) + cnt << '\n';
  return 0;
}
