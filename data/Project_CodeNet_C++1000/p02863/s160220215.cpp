#include <bits/stdc++.h>
using namespace std;

struct dat {
  long long a, b;
};
bool operator<(const dat &l, const dat &r) {
  if(l.a != r.a) return l.a < r.a;
  return l.b > r.b;
}

long long n, t;
vector<dat> v;
vector<vector<long long>> dp;

long long solve();

int main() {
  cin >> n >> t;
  v.resize(n);
  for(int i = 0; i < n; ++i) cin >> v[i].a >> v[i].b;
  sort(v.begin(), v.end());
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = 0;
  dp.assign(n + 1, vector<long long>(t + 1, 0));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < t; ++j) {
      dp[i + 1][j] = dp[i][j];
      ans = max(ans, dp[i][j] + v[i].b);
      if(j + v[i].a < t)
        dp[i + 1][j] =
            max(dp[i + 1][j], dp[i][j + v[i].a] + v[i].b);
      ans = max(ans, dp[i + 1][j]);
    }
  }
  return ans;
}
