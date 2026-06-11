#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int d[10][10];

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    string s = to_string(i);
    
    int h = to_string(i).front() - '0';
    int t = to_string(i).back() - '0';

    ++d[h][t];
  }

  ll ans = 0;

  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      ans += d[i][j] * d[j][i];
    }
  }

  cout << ans << '\n';

  return (0);
}
