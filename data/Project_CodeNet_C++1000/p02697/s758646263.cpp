#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> PLL;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (int i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT

signed main() {
  ll N, M;
  cin >> N >> M;
  if (N%2 == 0) {
    set<int> s;
    for (int i = 1; i <= M; i++) {
      int j = N + 1 - i;
      if (s.find(j-i) != s.end() || (j-i) == N-(j-i)) {
        j--;
      }
      s.insert(j-i);
      s.insert(N-(j-i));
      cout << j << " " << i << endl;
    }
  } else {
    for (int i = 1; i <= M; i++) {
      int j = N + 1 - i;
      cout << j << " " << i << endl;
    }
  }
  return 0;
}
