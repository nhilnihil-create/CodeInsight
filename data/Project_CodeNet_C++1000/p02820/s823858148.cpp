#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n, k, r, s, p;
  cin >> n >> k >> r >> s >> p;
  string t;
  cin >> t;
  for (int i = 0; i < n; i++) {
    if (i + k < n && t[i] == t[i + k]) {
      t[i + k] = '0';
    }
  }
  ll ans = 0;
  for (char c : t) {
    if (c == 'r')
      ans += p;
    else if (c == 's')
      ans += r;
    else if (c == 'p')
      ans += s;
  }
  cout << ans << endl;
  return 0;
}