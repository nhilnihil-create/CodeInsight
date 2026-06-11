#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

map<char, char> win;

int main() {
  ll k;
  string s;
  cin >> s >> k;

  ll ans = 0;
  int S = s.length();

  bool same = true;
  for (int i = 0; i < S; i++) {
    if (s[0] != s[i]) same = false;
  }
  if (same) {
    cout << S * k / 2 << endl;
    return 0;
  }

  s += "+-*/";
  for (int i = 0; i < S; i++) {
    if (s[i] == s[i + 1]) {
      auto j = i;
      while (s[j] == s[i]) j++;
      ans += (j - i) / 2;
      i = j - 1;
    }
  }
  ans *= k;

  int l(1), r(1);
  for (int i = 0; i < S - 1; i++) {
    if (s[i] != s[i + 1]) break;
    l++;
  }
  for (int i = S - 1; i > 0; i--) {
    if (s[i] != s[i - 1]) break;
    r++;
  }

  if (s[0] == s[S - 1] && ((r * l) % 2 != 0)) {
    ans += k - 1;
  }
  cout << ans << endl;
}
