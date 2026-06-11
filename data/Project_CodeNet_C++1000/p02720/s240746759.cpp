#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

string next(string s) {
  int n = s.length();
  bool nine = true;
  for (int i = 0; i < n; i++) nine &= s[i] == '9';
  if (nine) {
    string ret = "1";
    rep(i, n) ret += "0";
    return ret;
  }

  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '9') continue;
    int diff = 0;
    if (i > 0) diff = s[i - 1] - s[i];
    if (diff == 0 || diff == 1) {
      s[i]++;
      for (int j = i + 1; j < n; j++) {
        char c = s[j - 1] - 1;
        s[j] = max('0', c);
      }
      break;
    }
  }
  return s;
}

int main() {
  int k;
  cin >> k;

  string ans = "0";
  rep(i, k) ans = next(ans);

  cout << ans << endl;
}
