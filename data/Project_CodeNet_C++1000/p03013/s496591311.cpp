// g++ .cpp && ./a.out
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef pair<int, int> p;
typedef long long ll;

const int mod = 1000000007;

const int inf = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> ok(n + 1);
  vector<int> dp(n + 1);
  rep(i, m) {
    cin >> a[i];
    ok[a[i]]++;
  }
  dp[0] = 1;
  if (ok[1])
    dp[1] = 0;
  else
    dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (ok[i])
      dp[i] = 0;
    else
      dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
  }
  cout << dp[n] << endl;
}
