#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, ans = 0;
  string s;
  cin >> n >> s;
  rep(i, n - 2) {
    string ss = s.substr(i, 3);
    if (ss == "ABC") ans++;
  }
  cout << ans;
  return 0;
}
