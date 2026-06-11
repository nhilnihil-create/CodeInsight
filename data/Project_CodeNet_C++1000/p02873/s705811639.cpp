#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;

  cin >> s;

  vector<long> a((int)s.size() + 1), b((int)s.size() + 1);

  int cnt = 0;
  if (s[0] == '<') {
    a[0] = cnt;
    cnt++;
  }

  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '<') {
      a[i + 1] = cnt;
      cnt++;
    } else {
      cnt = 1;
    }
  }

  cnt = 0;
  if (s[(int)s.size() - 1] == '>') {
    b[s.size()] = cnt;
    cnt++;
  }

  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '>') {
      b[i] = cnt;
      cnt++;
    } else {
      cnt = 1;
    }
  }

  long ans = 0;

  for (int i = 0; i < (int)s.size() + 1; i++) {
    ans += max(a[i], b[i]);
  }

  cout << ans;

  return 0;
}