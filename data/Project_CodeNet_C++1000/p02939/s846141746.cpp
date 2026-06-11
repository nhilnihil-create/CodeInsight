#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  string t = "";
  rep(i, s.size()) {
    for (int j = 1; i + j <= s.size(); j++) {
      string u = s.substr(i, j);
      if (t != u) {
        ans++;
        i += j - 1;
        t = u;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}