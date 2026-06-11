#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n) - 1; 0 <= i; --i)
using namespace std;
using ll = long long;
using arr = vector<ll>;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;
constexpr int MAX = 2020;

string s, t;

int main()
{
  cin >> s >> t;
  int n = (int)s.size();
  int m = (int)t.size();
  s += s;
  vector<arr> next(n * 2 + 1, arr(26, -1));
  RREP(i, n * 2 - 1) {
    REP(j, 26) {
      if (s[i] - 'a' == j) {
        next[i][j] = i;
      } else {
        next[i][j] = next[i + 1][j];
      }
    }
  }

  ll ans = 0;
  ll pos = 0;
  REP(i, m) {
    if (next[pos][t[i] - 'a'] == -1) {
      cout << -1;
      return 0;
    }
    ans += next[pos][t[i] - 'a'] - pos + 1;
    pos = (next[pos][t[i] - 'a'] + 1) % n;
  }
  cout << ans;
  return 0;
}