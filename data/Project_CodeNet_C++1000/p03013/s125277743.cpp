#include <bits/stdc++.h>
using namespace std;
const  long long INF = 1LL << 60;
long long dp[100010];
long long h[100010];

template<class T> void chmin(T &a, T b) {
  if (a>b) {
    a = b;
  }
}
template<class T> inline void chmax(T &a, T b) {
  if (a<b) {
    a = b;
  }
}

int main() {
  int n; cin >> n;
  int m; cin >> m;

  for (int i = 0; i < 100010; i++) {
    dp[i] = -1;
  }
  int a[100010];
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    dp[a[i]] = -10;
  }
  
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (dp[i] == -10) continue;
    if (i == 1) dp[1] = 1;
    if (dp[i-1]==-10 && dp[i-2]==-10) {
      cout << 0 << endl;
      return 0;
    }
    else if (dp[i-1] == -10) {
      dp[i] = dp[i-2];
    }
    else if (dp[i-2] == -10) {
      dp[i] = dp[i-1];
    }
    else dp[i] = (dp[i-1]+dp[i-2])%1000000007;    
  }
  cout << dp[n] << endl;
}