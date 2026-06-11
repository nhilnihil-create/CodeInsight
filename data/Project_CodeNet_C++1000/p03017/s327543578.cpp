#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  --a, --b, --c, --d;

  bool jump = true;
  if (c > d) {
    int cnt = 0, tmp = 0;
    for (int i = b - 1; i < min(d + 2, c); ++i) {
      if (s[i] == '#') {
        tmp = 0;
        continue;
      }
      ++tmp;
      cnt = max(cnt, tmp);
    }
    if (cnt < 3)
      jump = false;
  }

  vector<bool> va(n);
  va[a] = true;
  for (int i = a; i < n; ++i) {
    if (s[i] == '#')
      continue;
    if (i > 0)
      va[i] = va[i] || va[i - 1];
    if (i > 1)
      va[i] = va[i] || va[i - 2];
  }

  vector<bool> vb(n);
  vb[b] = true;
  for (int i = b; i < n; ++i) {
    if (s[i] == '#')
      continue;
    if (i > 0)
      vb[i] = vb[i] || vb[i - 1];
    if (i > 1)
      vb[i] = vb[i] || vb[i - 2];
  }

  if (c != d && va[c] && vb[d] && jump)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}