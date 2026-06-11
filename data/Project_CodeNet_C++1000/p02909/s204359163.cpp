#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  vector<string> ans = {"Sunny", "Cloudy", "Rainy"};
  if (s[0] == 'S') cout << ans[1] << '\n';
  else if (s[0] == 'C') cout << ans[2] << '\n';
  else cout << ans[0] << '\n';
  return 0;
}