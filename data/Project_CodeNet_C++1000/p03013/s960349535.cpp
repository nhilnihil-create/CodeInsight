#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
ll const MOD = 1e9 + 7;

int main() {
  ll N, M;
  cin >> N >> M;
  set<ll> broken;
  ll a;
  for (int i = 0; i < M; i++) {
    cin >> a;
    broken.insert(a);
  }
  vector<ll> dp(N + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= N; i++) {
    if (broken.find(i) != broken.end()) continue;
    if (broken.find(i - 1) == broken.end()) {
      dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }
    if (0 <= i - 2 && broken.find(i - 2) == broken.end()) {
      dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
  }
  cout << dp[N] << endl;
  return 0;
}