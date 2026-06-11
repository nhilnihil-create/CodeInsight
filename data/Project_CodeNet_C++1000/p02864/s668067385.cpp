
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
using ll = long long;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 60;

int main() {
  //
  ll n, k;
  cin >> n >> k;
  vl h(n + 1, 0);
  rep(i, n) cin >> h[i + 1];
  vvl data(n + 1, vl(n + 1, 0));
  REP(x, 1, n + 1) data[x][1] = h[x];
  REP(x, 1, n + 1) {
    REP(y, 2, n - k + 1) {
      ll tmp = INF;
      REP(i, 1, x) { tmp = min(tmp, data[i][y - 1] + max(0LL, h[x] - h[i])); }
      data[x][y] = tmp;
    }
  }
  ll ans = INF;
  REP(i, 1, n + 1) { ans = min(ans, data[i][n - k]); }
  cout << ans << endl;
  return 0;
}
