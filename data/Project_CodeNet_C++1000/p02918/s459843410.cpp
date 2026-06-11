#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 0;
  rep(i, n) {
    if (i < n-1 && s[i] == 'R' && s[i+1] == 'R') ans++;
    else if (i > 0 && s[i] == 'L' && s[i-1] == 'L') ans++;
  }
  ans = min(n-1, ans + 2 * k);
  cout << ans << '\n';  
  return 0;
}