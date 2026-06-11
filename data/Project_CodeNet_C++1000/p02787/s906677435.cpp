#include <math.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

using ll = long long;
typedef pair<ll, ll> P_ll;
typedef pair<int, int> P;

const ll INF_ll = 1e17;
const int INF = 1e8;

int main() {
  int N, H;
  cin >> H >> N;
  vector<vector<int>> AB(N, vector<int>(2, 0));
  for (int i = 0; i < N; i++) {
    cin >> AB[i][0] >> AB[i][1];
  }
  vector<vector<int>> dp(N + 1, vector<int>(H + 1, INF));
  for (int i = 0; i <= N; i++) {
    dp[i][0] = 0;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= H; j++) {
      if (j < AB[i][0]) {
        dp[i + 1][j] = min(dp[i][j], AB[i][1]);
      } else {
        dp[i + 1][j] = min(dp[i][j], min(dp[i][j - AB[i][0]] + AB[i][1],
                                         dp[i + 1][j - AB[i][0]] + AB[i][1]));
      }
    }
  }
  cout << dp[N][H] << endl;
  // for (int i = 0; i <= N; i++) {
  //   for (int j = 0; j <= H; j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
}