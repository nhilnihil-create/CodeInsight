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
#include <queue>
#include <random>
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

  int n; cin >> n;
  if (__builtin_popcount(n) == 1) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  vector<int> a, b;
  a.emplace_back(1); b.emplace_back(2);
  a.emplace_back(2); b.emplace_back(3);
  a.emplace_back(3); b.emplace_back(1 + n);
  a.emplace_back(1 + n); b.emplace_back(2 + n);
  a.emplace_back(2 + n); b.emplace_back(3 + n);
  for (int i = 5; i <= n; i += 2) {
    a.emplace_back(i - 1); b.emplace_back(i);
    a.emplace_back(i); b.emplace_back(1 + n);
    a.emplace_back(1 + n); b.emplace_back(i - 1 + n);
    a.emplace_back(i - 1 + n); b.emplace_back(i + n);
  }
  if (n % 2 == 0) {
    int tmp = n | 1, one = 0;
    for (int i = 17; i >= 0; --i) {
      if (tmp >> i & 1) {
        one = 1 << i;
        tmp ^= 1 << i;
        break;
      }
    }
    a.emplace_back(n); b.emplace_back(one + n);
    a.emplace_back(tmp); b.emplace_back(n + n);
  }
  REP(i, 2 * n - 1) cout << a[i] << ' ' << b[i] << '\n';
  return 0;
}
