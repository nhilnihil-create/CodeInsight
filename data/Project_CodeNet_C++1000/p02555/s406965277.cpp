#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;

int main() {
  int s;
  cin >> s;
  vector<ll> dp(s+1);
  dp[0] = 1;
  for(int i = 1;i <= s;i++) {
    for(int j = 0;j <= (i-3);j++) {
      dp[i] += dp[j];
      dp[i] %= mod;
    }
  }
  cout << dp[s] << endl;
}