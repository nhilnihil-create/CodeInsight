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
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; string s; cin >> n >> s;
  map<char, int> mp;
  mp['W'] = 0; mp['B'] = 1;
  REP(i, n * 2) {
    int which = (mp[s[i]] + n * 2 - 1 - i) % 2;
    s[i] = (which == 0 ? 'W' : 'B');
  }
  int cnt = 0;
  long long ans = 1;
  REP(i, n * 2) {
    if (s[i] == 'W') {
      ++cnt;
    } else {
      if (cnt == 0) {
        cout << 0 << '\n';
        return 0;
      }
      (ans *= cnt) %= MOD;
      --cnt;
    }
  }
  if (cnt > 0) {
    cout << 0 << '\n';
    return 0;
  }
  FOR(i, 1, n + 1) (ans *= i) %= MOD;
  cout << ans << '\n';
  return 0;
}
