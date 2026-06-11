#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
int r, s, p;

int f(int hand, char enemy)
{
  if (hand == 0 && enemy == 's') return r;
  if (hand == 1 && enemy == 'p') return s;
  if (hand == 2 && enemy == 'r') return p;

  return 0;
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  cin >> r >> s >> p;

  string t;
  cin >> t;

  vector<vector<char>> c(k);
  for (int i = 0; i < n; ++i) c[i % k].emplace_back(t[i]);

  int ans = 0;
  for (int i = 0; i < k; ++i) {
    int siz = c[i].size();

    int dp[siz+1][3];
    memset(dp, 0, sizeof(dp));

    for (int j = 0; j < siz; ++j) {
      for (int before = 0; before < 3; ++before) {
        for (int now = 0; now < 3; ++now) {
          if (now == before) continue;
          dp[j+1][now] = max(dp[j+1][now], dp[j][before] + f(now, c[i][j]));
        }
      }
    }

    ans += *max_element(dp[siz], dp[siz]+3);
  }

  cout << ans << '\n';

  return (0);
}