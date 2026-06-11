#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  string ans;
  while (n > 0) {
    int m = n % 26;
    if (m == 0) {
      ans.push_back('z');
      n--;
    } else {
      ans.push_back('a' + m - 1);
    }
    n /= 26;
  }
  for (int i = (int)ans.size() - 1; ~i; i--) {
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}