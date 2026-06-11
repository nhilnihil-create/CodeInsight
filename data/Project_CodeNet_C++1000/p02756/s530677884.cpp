#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string s0 = s.substr(0, 1);
  int ns = (int)s.size();
  string sl;
  if (ns != 1) sl = s.substr(ns - 1);
  string rest;
  if (ns >= 3) rest = s.substr(1, ns - 2);
  int q;
  cin >> q;
  int rev = 1;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1)
      rev = -rev;
    else {
      int f;
      cin >> f;
      string c;
      cin >> c;
      if ((f == 1 && rev == 1) || (f == 2 && rev == -1)) {
        s0.insert(0, c);
      } else {
        sl.append(c);
      }
    }
  }
  s = s0 + rest + sl;
  if (rev == -1) reverse(s.begin(), s.end());
  cout << s << '\n';
  return 0;
}