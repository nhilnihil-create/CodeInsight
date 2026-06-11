#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int dp[1100][11000];

int main() {
  int h, n;
  cin >> h >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, n + 1) rep(j, h + 1) dp[i][j] = INF;
  
  dp[0][0] = 0;
  rep(i, n) rep(j, h + 1) {

    // 使わない場合
    chmin(dp[i + 1][j], dp[i][j]);

    // 使う場合
    int nj = min((int)j + a[i], h);
    chmin(dp[i + 1][nj], dp[i + 1][j] + b[i]);

  }
  cout << dp[n][h] << endl;
}