#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int ans = 0;
  rep(i, 1000) {
    string t;
    int x = i;
    rep(j, 3) {
      t.push_back('0' + x % 10);
      x /= 10;
    }
    int ti = 0;
    rep(j, n) {
      if (s[j] == t[ti]) {
        ti++;
        if (ti == 3) break;
      }
    }
    if (ti == 3) ans++;
  }
  cout << ans << endl;
  return 0;
}
