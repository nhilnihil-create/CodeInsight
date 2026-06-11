#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

const int mod = 1000000007;

signed main() {
  int N, M; cin >> N >> M;
  vector<bool> t(N, true);
  rep(i, M) {
    int a; cin >> a;
    t[a] = false;
  }
  
  vector<int> dp(N+1, 0);
  dp[0] = 1;
  rep(i, N) {
    if(!t[i]) continue;
    if(t[i+1]) {
      dp[i+1] += dp[i];
      dp[i+1] %= mod;
    }
    if(i < N-1 && t[i+2]) {
      dp[i+2] += dp[i];
      dp[i+2] %= mod;
    }
  }

  cout << dp[N] << endl;

}