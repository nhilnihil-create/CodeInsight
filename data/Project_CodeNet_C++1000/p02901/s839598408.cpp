#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <string>
#include <utility>
#include <cassert>

using namespace std;
typedef long long ll;

const int MAXM = 1024;
int a[MAXM], to_msk[MAXM];
int dp[MAXM][1<<12];
const int INF = 1e9;

int n, m;

int go(int pos, int msk) {
  if (pos == m) {
    if (msk + 1 == (1 << n)) {
      return 0;
    }
    return INF;
  }
  if (dp[pos][msk] != -1) return dp[pos][msk];
  int op1 = go(pos + 1, msk);
  int op2 = a[pos] + go(pos + 1, msk | to_msk[pos]);
  return dp[pos][msk] = min(op1, op2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    int b;
    cin >> b;
    int msk = 0;
    for (int j = 0; j < b; j++) {
      int x;
      cin >> x;
      x--;
      msk = msk | (1 << x);
    }
    to_msk[i] = msk;
  }
  for (int i = 0; i < MAXM; i++)
    for (int j = 0; j < (1 << 12); j++) 
      dp[i][j] = -1;

  int res = go(0, 0);
  if (res > INF / 2) res = -1;
  cout << res << endl;
  return 0;
}
