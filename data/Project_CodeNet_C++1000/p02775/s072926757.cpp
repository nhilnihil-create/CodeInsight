#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;
const int MAXN = 1001001;

int dp[MAXN][2];

int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  s += '0';
  int n = s.length();
  rep(i, MAXN)rep(j, 2) dp[i][j] = INF;

  dp[0][0] = 0;
  rep(i, n)rep(j, 2) {
    int c = s[i] - '0';
    c += j; // 繰り下がりが起こる場合に桁に1を足しておく
    rep(a, 10) {
      int ni = i + 1, nj = 0;
      int b = a - c;
      if (b < 0) {
        nj = 1;
        b += 10;
      }
      chmin(dp[ni][nj], dp[i][j] + (int)a + b);
    }

  }
  int ans = dp[n][0];
  cout << ans << endl;
}