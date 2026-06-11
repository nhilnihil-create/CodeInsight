#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x) for (auto&& v : (x))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))

int main() {
  ll h, c = 1;
  cin >> h;
  ll result = 0;
  while (h > 0) {
    result += c;
    h /= 2;
    c *= 2;
  }
  cout << result << endl;
}
