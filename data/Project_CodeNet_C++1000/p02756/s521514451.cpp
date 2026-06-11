#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
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
        s.insert(0, c);
      } else {
        s.append(c);
      }
    }
  }
  if (rev == -1) reverse(s.begin(), s.end());
  cout << s << '\n';
  return 0;
}