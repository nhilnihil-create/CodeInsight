#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x) for (auto&& v : (x))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))

ll a[200100];
int main() {
  ll h, n;
  cin >> h >> n;
  rep(i, n) cin >> a[i];
  ll sum = 0;
  rep(i, n) sum += a[i];
  cout << (sum >= h ? "Yes" : "No") << endl;
}
