#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define append push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int mod = 1000000007;
int dp[100010][13];

int main() {
  string s;
  cin >> s;
  int n = len(s);
  dp[0][0] = 1;
  rep(i,0,n) rep(j,0,13) {
    int ni = i+1, nj;
    if (s[i] == '?') {
      rep(nd,0,10) {
        nj = (j*10 + nd) % 13;
        dp[ni][nj] += dp[i][j];
        dp[ni][nj] %= mod;
      }
    } else {
      int d = s[i]-'0';
      nj = (j*10 + d) % 13;
      dp[ni][nj] += dp[i][j];
      dp[ni][nj] %= mod;
    }
  }
  int ans = dp[n][5];
  cout << ans << endl;
  return 0;
}
