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
  int S;
  cin >> S;
  vector<ll> dp(S + 1, 0);
  dp[0] = 1;
  ll mod = 1000000007;
  for (int i = 0; i < S + 1; i++) {
    for (int j = 0; j < (i - 3) + 1; j++) {
      dp[i] += dp[j];
      dp[i] %= mod;
    }
  }
  cout << dp[S] << endl;

  return 0;
}