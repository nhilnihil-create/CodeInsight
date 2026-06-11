// author: erray
#include<bits/stdc++.h>
 
using namespace std;

const int mod = (int) 1e9 + 7;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> s(n), t(m);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> t[i];
  }
  vector<long long> dp(m + 1, 1);
  for (int i = 0; i < n; ++i) {
    vector<long long> newDp(m + 1);
    for (int j = 1; j <= m; ++j) {
      if (s[i] == t[j - 1]) {
        (newDp[j] += dp[j - 1]) %= mod;  
      }  
    }
    for (int j = 1; j <= m; ++j) {
      (newDp[j] += newDp[j - 1]) %= mod;
    }
    for (int j = 0; j <= m; ++j) {
      (newDp[j] += dp[j]) %= mod;
    }
    swap(dp, newDp);
  }
  cout << dp.back() << '\n';
}