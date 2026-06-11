#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

int main() {
  
  string s; cin >> s;
  int n = s.size();
  vector<vector<lint>> dp(n + 1, vector<lint> (3, -INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (dp[i][j] == -INF) continue;
      // j == 0 なら，どんな分割でもあり
      if (j == 0) {
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + 1);
        if (i + 2 <= n) dp[i + 2][2] = max(dp[i + 2][2], dp[i][j] + 1);
        continue;
      }

      for (int nj = 1; nj <= 2; nj++) {
        if (i + nj <= n) {
          if (s.substr(i - j, j) == s.substr(i, nj)) continue;

          dp[i + nj][nj] = max(dp[i + nj][nj], dp[i][j] + 1);
        }
      }
    }
  }

  cout << max(dp[n][1], dp[n][2]) << endl;
  
  return 0;
}
