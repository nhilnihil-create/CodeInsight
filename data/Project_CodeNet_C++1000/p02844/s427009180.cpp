#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  // map<char, std::size_t> m;
  // for (char c = '0'; c <= '9'; c++) {
  //   auto i = s.rfind(c);
  //   if (i == s.npos) i = 0;
  //   m[c] = i;
  // }

  int ans = 0;
  for (char c = '0'; c <= '9'; c++) {
    auto i = s.find(c);
    if (i == s.npos) continue;
    for (char d = '0'; d <= '9'; d++) {
      auto j = s.find(d, i + 1);
      if (j == s.npos) continue;
      for (char e = '0'; e <= '9'; e++) {
        auto k = s.find(e, j + 1);
        if (k == s.npos) continue;
        ans++;
      }
    }
  }
  cout << ans << endl;
}
