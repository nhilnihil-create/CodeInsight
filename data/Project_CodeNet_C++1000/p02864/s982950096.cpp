#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll h[303];
ll dp[303][303];
const ll INF = 1e17;

int main() {
  int n,k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> h[i];

  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      dp[i][j] = INF;
    }
  }
  
  dp[0][0] = 0;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      ll tmp = INF;
      for(int k = 0; k < j; k++) {
	tmp = min(tmp,dp[i-1][k] + max(0ll,h[j] - h[k]));
      }
      dp[i][j] = tmp;
    }
  }

  ll ans = INF;
  for(int i = 0; i <= n; i++) {
    ans = min(ans,dp[n-k][i]);
  }
  cout << ans << endl;
}
  
      
      
