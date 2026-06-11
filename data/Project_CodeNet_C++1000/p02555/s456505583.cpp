#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
#define _GLIBCXX_DEBUG
int mod = 1e9+7;

int main() {
  ll s; cin >> s;
  ll dp[2010];
  dp[0] = 1;

  for(int i = 0; i <= s; i++){
    if(i >= 3) dp[i] = dp[i-1] + dp[i-3];
    dp[i] %= mod;
  }

  cout << dp[s] << endl;
}
