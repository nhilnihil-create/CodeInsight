#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> PLL;
#define chmax(x, y) do { x = max(x, y); } while(0)
#define chmin(x, y) do { x = min(x, y); } while(0)
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
template<typename T>
using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;

signed main() {
  string s;
  cin >> s;
  for (auto &c : s) {
    if (c == '?')
      c = 'D';
  }
  cout << s << endl;
  return 0;
}
