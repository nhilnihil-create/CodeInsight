#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;

int main() {
  int h, n;
  cin >> h >> n;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];

  vector<int> dp(h + 1, INF);
  dp[h] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = h; j >= 0; j--) {
      dp[max(j - a[i], 0)] = min(dp[max(j - a[i], 0)], dp[j] + b[i]);
    }
  }

  cout << dp[0] << endl;
  return 0;
} 