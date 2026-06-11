#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int ans[500][500];
void solve(int l, int r, int level) {
  if (l + 1 == r) return;
  int border = (l + r + 1) / 2;
  FOR(i, l, border) FOR(j, border, r) ans[i][j] = level;
  solve(l, border, level + 1);
  solve(border, r, level + 1);
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  memset(ans, -1, sizeof(ans));
  int n; cin >> n;
  solve(0, n, 1);
  REP(i, n) {
    FOR(j, i + 1, n) cout << ans[i][j] << (j + 1 == n ? '\n' : ' ');
  }
  return 0;
}
