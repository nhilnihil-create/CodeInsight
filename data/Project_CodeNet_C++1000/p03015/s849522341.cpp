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

LL dp[100002][2];  // keta, smaller

LL add(LL a, LL b) { return (a+b) % kMod; }
LL mul(LL a, LL b) { return (a*b) % kMod; }

int main() {
  string L; cin >> L;
  dp[0][0] = 1, dp[0][1] = 0;  // tight, smaller
  for (int i = 0; i < L.size(); ++i) {
    if (L[i] == '1') {
      dp[i + 1][0] = mul(dp[i][0], 2);
      dp[i + 1][1] = add(dp[i][0], mul(dp[i][1], 3));
    } else {
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = mul(dp[i][1], 3);
    }
  }
  cout << add(dp[L.size()][0], dp[L.size()][1]) << endl;
}
