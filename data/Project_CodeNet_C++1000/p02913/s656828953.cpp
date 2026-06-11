#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
int dp[5005][5005];

int main() {
  int n;
  string s;
  cin >> n >> s;

  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if(s[i] == s[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
      else dp[i][j] = 0;
    }
  }

  int ans = 0;
  rep(i, n)rep(j, n) {
    if(i > j) continue;
    int len = min(j - i, ll(dp[i][j]));
    ans = max(ans, len);
  }
  cout << ans << endl;
}