#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;
const ll inf = 1LL<<60;

int main()
{
  string s; cin >> s;
  reverse(s.begin(), s.end());
  s.push_back('0');
  int l = s.size();

  vector<vector<ll>> dp(l+1, vector<ll>(2, inf));
  dp[0][0] = 0;
  for (int i=0; i<l; i++) {
    for (int j=0; j<2; j++) {
      int n = s[i]-'0';
      n += j;
      for (int a=0; a<10; a++) {
        int b = a-n;
        if (b < 0) {
          b += 10;
          dp[i+1][1] = min(dp[i+1][1], dp[i][j]+a+b);
        } else {
          dp[i+1][0] = min(dp[i+1][0], dp[i][j]+a+b);
        }
      }
    }
  }
  cout << dp[l][0] << endl;

  return 0;
}
