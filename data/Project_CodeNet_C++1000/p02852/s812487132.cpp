#line 1 "/mnt/c/Users/leafc/dev/compro/lib/template.hpp"


#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>

using namespace std;

#line 2 "tmp.cpp"

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> dp(n + 1, -1);

  dp[n] = 0;
  int cur = n;
  while (cur > 0) {
    int far = cur;
    FOR(i, 1, m + 1) {
      if (cur - i < 0)
        break;
      if (s[cur - i] == '0') {
        dp[cur - i] = dp[cur] + 1;
        far = cur - i;
      }
    }
    if (cur == far) {
      cout << -1 << endl;
      return 0;
    }
    cur = far;
  }

  // 復元
  vi ans;
  cur = 0;
  while (cur <= n) {
    FOR(i, 1, m + 1) {
      if (cur + i > n)
        break;
      if (dp[cur + i] == dp[cur] - 1) {
        ans.push_back(i);
        cur += i;
        break;
      }
    }
    if (cur == n)
      break;
  }

  REP(i, (int)ans.size()) { cout << ans[i] << (i == (int)ans.size() - 1 ? "\n" : " "); }

  return 0;
}
