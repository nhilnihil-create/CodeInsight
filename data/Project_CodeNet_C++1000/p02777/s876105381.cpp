#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x) for (auto&& v : (x))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))

int main() {
  string s, t, u;
  ll a, b;
  cin >> s >> t >> a >> b >> u;
  cout << a - (s == u) << ' ' << b - (t == u) << endl;
}
