#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef tuple<int,int,int> TP;
constexpr int mod = 1e9 + 7;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> dp(13, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    vector<int> ndp(13, 0);
    for (int j = 0; j < 13; j++) {
      for (int k = 0; k < 10; k++) {
        if (s[i] == '?' || int(s[i] - '0') == k) (ndp[(j * 10 + k) % 13] += dp[j]) %= mod;
      } 
    }
    dp = move(ndp);
  }
  cout << dp[5] << endl;
  return 0; 
} 