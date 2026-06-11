
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <stack>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int) (v).size()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

ll dp[100005][2];
string t, L = "x";

int main(void) {
  cin >> t;
  int n = sz(t);
  L += t;
  
  dp[0][0] = 1;
  for (int i=1; i<=n; i++) for (int j=0; j<=1; j++) {
    int u = j ? 1 : L[i] - '0';
    for (int k=0; k<=u; k++) {
      dp[i][(j || k<u)] += dp[i-1][j] * (k ? 2 : 1);
      dp[i][j] %= MOD;
      
    }
  
  }
  
  cout << (dp[n][0] + dp[n][1])%MOD  << "\n";

  return 0;
}
