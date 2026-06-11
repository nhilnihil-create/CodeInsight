#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using arr = vector<ll>;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;
constexpr int MAX = 2020;

string s, t;
set<int> st[26];

int main()
{
  cin >> s >> t;
  int n = (int)s.size();
  int m = (int)t.size();
  s += s;


  for(int i = 0; i < n * 2; ++i) {
    st[s[i] - 'a'].insert(i);
  }

  ll ans = 0, pos = 0;
  for(int i = 0; i < m; ++i) {
    if (st[t[i] - 'a'].empty()) {
      cout << -1;
      return 0;
    }
    int next = *st[t[i] - 'a'].lower_bound(pos) + 1;
    ans += next - pos;
    pos = next % n;
  }
  cout << ans;
  return 0;
}