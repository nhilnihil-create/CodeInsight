#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int dp[1000010][2];

int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  s += '0';
  int n = s.length();

  rep(i, 1000010) rep(j, 2) {
    dp[i][j] = INF;
  }
  dp[0][0] = 0;
  rep(i, n) rep(j, 2) {
    int ni = i + 1;
    int c = s[i] - '0';
    c += j;
    if (c < 10) chmin(dp[ni][0], dp[i][j] + c);
    if (c > 0)  chmin(dp[ni][1], dp[i][j] + (10 - c));
  }
  cout << dp[n][0] << endl;
}