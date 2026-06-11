#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;
int n;
string s;
ll dp[maxn][2]; //1: match, 0:already lower

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

  cin>>s;
  n = s.length();
  //s = "*" + s;
  
  dp[0][1] = 1;

  for (int i=0; i<n; i++) {
    if (s[i] == '1') {
      dp[i+1][1] += 2LL*dp[i][1]; //01,10, two ways to keep up
      dp[i+1][0] += dp[i][1]; //00, dip down
      dp[i+1][0] += 3LL*dp[i][0]; //00,01,10, doesn't matter
    } else {
      dp[i+1][1] += dp[i][1]; //00, only 1 way to keep up
      dp[i+1][0] += 3LL*dp[i][0]; //00,01,10, doesn't matter
    }

    dp[i+1][0] %= mod;
    dp[i+1][1] %= mod;
  }

  ll ans = dp[n][0]+dp[n][1];
  ans %= mod;
  ans += mod;
  ans %= mod;
  cout<<ans<<endl;
  return 0;
}
// don't forget to read in the input :^)
