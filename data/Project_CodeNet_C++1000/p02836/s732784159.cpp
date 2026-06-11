#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define f1(i, a, b) for (int i = a; i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  string s, t;
  cin >> s;
  t = s;
  reverse(s.begin(), s.end());
  int ans = 0;
  rep(i, s.size() / 2) {
    if (s[i] == t[i]) continue;
    ans++;
  }
  cout << ans << '\n';
  return 0;
}