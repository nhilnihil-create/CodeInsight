#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  int S = s.length();
  vector<int> num(S + 1);

  s = '>' + s + "<";
  rep(k, 2) {
    rep(i, S) {
      if (s.substr(i, 2) == "><") {
        num[i] = 0;
        int j = i + 1;
        while (s[j] == '<') {
          num[j] = max(num[j], num[j - 1] + 1);
          j++;
        }
        i = j - 1;
      }
    }
    reverse(s.begin(), s.end());
    int l = s.length();
    rep(i, l) s[i] = (s[i] == '<') ? '>' : '<';
    reverse(num.begin(), num.end());
  }
  ll ans = 0;
  rep(i, S + 1) ans += num[i];
  cout << ans << endl;
}
