#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x) for (auto&& v : (x))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))

ll h[200100];
int main() {
  ll n, k;
  cin >> n >> k;
  rep(i, n) cin >> h[i];
  sort(h, h + n);
  ll result = 0;
  rep(i, max(n - k, 0ll)) result += h[i];
  cout << result << endl;
}
