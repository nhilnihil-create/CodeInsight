#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  a--;
  b--;
  c--;
  d--;
  string s;
  cin >> s;

  bool ok = true;
  if (c < d /* A B C D */) {
    for (int i = a + 1; i <= c; i++) {
      if (s[i] == '#' && s[i - 1] == '#') {
        ok = false;
        break;
      }
    }
    for (int i = b + 1; i <= d; i++) {
      if (s[i] == '#' && s[i - 1] == '#') {
        ok = false;
        break;
      }
    }
  } else { /* A B D C */
    for (int i = a + 1; i <= c; i++) {
      if (s[i] == '#' && s[i - 1] == '#') {
        ok = false;
        break;
      }
    }
    for (int i = b + 1; i <= d; i++) {
      if (s[i] == '#' && s[i - 1] == '#') {
        ok = false;
        break;
      }
    }
    bool jump = false;
    for (int i = b; i <= d; i++) {
      if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') {
        jump = true;
        break;
      }
    }
    if (!jump) {
      ok = false;
    }
  }

  if (ok) {
    puts("Yes");

  } else {
    puts("No");
  }

  return 0;
}
