#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>
#include <string>
#include <cassert>
#include <bitset>

using namespace std;
typedef long long ll;

int main() {
  string S;
  cin >> S;
  int N = S.size();

  vector<vector<int> > dp(N, vector<int>(2));

  // Init
  {
    int d = S[0] - '0';
    dp[0][0] = d;
    dp[0][1] = 10 - d;
  }

  // Iterate
  for (int i = 1; i < N; ++i) {
    int d = S[i] - '0';
    if (d != 9) {
      dp[i][0] = min(dp[i-1][0] + d, dp[i-1][1] + d + 1);
      dp[i][1] = min(dp[i-1][0] + (10-d), dp[i-1][1] + (10-(d+1)));
    } else {
      dp[i][0] = dp[i-1][0] + d;
      dp[i][1] = min(dp[i-1][0] + (10-d), dp[i-1][1] + (10-(d+1)));
    }
  }

  // Terminate
  int ans = min(dp[N - 1][0], dp[N - 1][1] + 1);
  cout << ans << endl;
  
  return 0;
}
