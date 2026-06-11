#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  using ll = long long;
  ll ans = 0, min_n = 0, i = 0;
  while (i < s.size()) {
    if (s[i] == '<') {
      ans += min_n++;
      i++;
    } else {
      ll j = i, len = 1;
      while (j < s.size() && s[j] == s[i]) {
        j++;
        len++;
      }

      ll mx = max(min_n, len - 1);
      ans += mx;
      // len == 1: 0
      // len == 2: 0, 1
      // len == 3: 0, 1, 2
      ans += (len - 1) * (len - 2) / 2;
      min_n = 0;
      i += len - 1;
    }
  }

  if (s.back() == '<') {
    ans += min_n;
  }

  cout << ans << '\n';
  return 0;
}