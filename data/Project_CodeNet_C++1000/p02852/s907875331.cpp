#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
int dp[N];
int n, m;
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(dp, 255, sizeof dp);

  cin >> n >> m;
  cin >> s;

  int r = n - 1;
  int cur = n;
  dp[n] = 0;
  while (cur > 0) {
    if (dp[cur] == -1) {
      --cur;
      continue;
    }
    for (int i = max(0, cur - m); i <= min(cur - 1, r); ++i) {
      if (s[i] == '0') {
        dp[i] = dp[cur] + 1;
      }
    }
    r = min(r, cur - m - 1);
    --cur;
  }
  int s = dp[0];
  if (s == -1)
    cout << -1 << endl;
  else {
    s--;
    int start = 0;
    for (int i = 1; i <= n; ++i) {
      if (dp[i] == s) {
        s--;
        cout << i - start << endl;
        start = i;
      }
    }
  }
  
  return 0;
}
