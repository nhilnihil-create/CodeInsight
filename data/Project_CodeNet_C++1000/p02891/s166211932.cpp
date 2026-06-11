#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length(), k;
  cin >> k;

  long long a = 0, b = 0;
  bool a2b = false, b2b = false;

  { // a
    string t = s;
    for (int i = 1; i < n; i++) {
      if (t[i] == t[i - 1]) {
        t[i] = '.';
        a++;
      }
    }
    if (t[n - 1] == s[0]) a2b = true;
  }
  { // b
    string t = s;
    t[0] = '.';
    b++;
    for (int i = 1; i < n; i++) {
      if (t[i] == t[i - 1]) {
        t[i] = '.';
        b++;
      }
    }
    if (t[n - 1] == s[0]) b2b = true; 
  }
  cerr << a << ' ' << b << endl;

  long long ans = a; k--;
  if (!a2b) {
    ans += a * k;
  } else if (b2b) {
    ans += b * k;
  } else {
    ans += b * ((k + 1) / 2);
    ans += a * (k / 2);
  }

  cout << ans << endl;
  return 0;
}
