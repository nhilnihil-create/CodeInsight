#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  bool bad = false;
  for (int i = a; i < c; i++) {
    bad |= s[i] == '#' && s[i - 1] == '#';
  }
  for (int i = b; i < d; i++) {
    bad |= s[i] == '#' && s[i - 1] == '#';
  }
  if (bad) {
    cout << "No" << '\n';
    return 0;
  }
  if (c < d) {
    cout << "Yes" << '\n';
    return 0;
  }
  bool good = false;
  for (int i = b; i <= d; i++) {
    good |= s[i] == '.' && s[i - 1] == '.' && i > 2 && s[i - 2] == '.';
  }
  cout << (good ? "Yes" : "No") << '\n';
  return 0; // :)
}
