#include <bits/stdc++.h>

// #LIB#

using namespace std;
using ll = long long;
#define double long double
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#ifdef ONLINE_JUDGE
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');
#endif

int main() {
  ll n, k;
  cin >> n >> k;
  ll en = (n - 1) * (n - 2) / 2 - k;
  if (en < 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << n - 1 + en << endl;
  repr(i, 1, n) cout << n << " " << i << endl;
  repr(i, 1, n) repr(j, i + 1, n) {
    if (en-- <= 0) goto end;
    cout << i << " " << j << endl;
  }
end:
  0;
}
