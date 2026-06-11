#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;
constexpr LL kInf = 1e18;

int state(int n) {
  int s = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; --x;
    s |= (1 << x);
  }
  return s;
}

LL dp[1 << 12];

int main() {
  int N, M; cin >> N >> M;
  for (int i = 0; i < (1 << N); ++i) dp[i] = kInf;
  dp[0] = 0;
  for (int i = 0; i < M; ++i) {
    int a, b; cin >> a >> b;
    int s = state(b);
    dp[s] = min(dp[s], (LL)a);
  }

  for (int s1 = 0; s1 < (1 << N); ++s1) {
    if (dp[s1] == kInf) continue;
    for (int s2 = s1 + 1; s2 < (1 << N); ++s2) {
      if (dp[s2] == kInf) continue;
      int s = s1 | s2;
      dp[s] = min(dp[s], dp[s1] + dp[s2]);
    }
  }

  LL x =  dp[(1 << N) - 1];
  if (x == kInf) cout << -1 << endl;
  else           cout << x << endl;
}
