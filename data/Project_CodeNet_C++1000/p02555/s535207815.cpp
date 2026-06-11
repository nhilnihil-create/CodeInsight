#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int dp[3010];

int main() {
  int n;
  cin >> n;
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) for (int j = i - 3; j >= 0; --j) {
    dp[i] += dp[j];
    dp[i] %= mod;
  }

  cout << dp[n] << endl;
}