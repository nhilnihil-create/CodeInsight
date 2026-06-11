#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <map>
#include <set>
 
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

vector<int> a;
int n, s;

ll dp[3001][3001];

#define MOD 998244353LL

int main()
{
  int i, j;

  cin >> n >> s;

  dp[0][0]=1;

  a.resize(n);
  for (i=0; i<n; i++) {
    cin >> a[i];
  }

  for (i=0; i<n; i++) {
    for (j=0; j<s+1; j++) {
//printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]); 
      dp[i+1][j] +=2 * dp[i][j];
      dp[i+1][j] %= MOD;
      if (j+a[i] <= s) {
        dp[i+1][j+a[i]] += dp[i][j];
        dp[i+1][j+a[i]] %= MOD;
      }
    }
  }
  cout << dp[n][s] << endl;
  return 0;
}
