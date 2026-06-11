#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 2e9;

int main() {
  int h, n;
  cin >> h >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector<int> dp(h+1, INF);
  dp[0] = 0;
  rep(i, h) rep(j, n) {
    int to = min(i + a[j], h);
    dp[to] = min(dp[to], dp[i] + b[j]);
  }
  cout << dp[h] << endl;
  return 0;
}