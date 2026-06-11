#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<string> ss(n);
  rep(i, n) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ss[i] = s;
  }
  sort(ss.begin(), ss.end());
  ll ans = 0;
  ll cnt = 0;
  for (int i = 1; i < n; i++) {
    if (ss[i - 1] == ss[i]) {
      cnt++;
    } else {
      ans += (cnt + 1) * cnt / 2;
      cnt = 0;
    }
  }
  ans += (cnt + 1) * cnt / 2;
  cout << ans << endl;

  return 0;
}