#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  int k;
  cin >> s >> k;
  char pre;
  ll cnt;

  ll ans1 = 0;
  cnt = 1;
  pre = s[0];
  for (int i = 1; i < s.size(); i++) {
    if (pre == s[i]) {
      cnt++;
    } else {
      ans1 += cnt / 2;
      cnt = 1;
      pre = s[i];
    }
  }
  ans1 += cnt / 2;

  if (cnt == s.size()) {
    cout << (s.size() * k) / 2 << endl;
    return 0;
  }

  if (k == 1) {
    cout << ans1 << endl;
    return 0;
  }

  string ss = s + s;
  ll ans2 = 0;
  cnt = 1;
  pre = ss[0];
  for (int i = 1; i < ss.size(); i++) {
    if (pre == ss[i]) {
      cnt++;
    } else {
      ans2 += cnt / 2;
      cnt = 1;
      pre = ss[i];
    }
  }
  ans2 += cnt / 2;

  ll dif = ans2 - ans1;
  cout << ans1 + (k - 1) * dif << endl;
  return 0;
}
