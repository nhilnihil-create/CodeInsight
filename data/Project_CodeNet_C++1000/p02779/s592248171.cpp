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
  ll n;
  cin >> n;
  rep(i, n) cin >> a[i];
  bool result = true;
  sort(a, a + n);
  rep(i, n - 1) {
    if (a[i] == a[i + 1]) {
      result = false;
      break;
    }
  }
  cout << (result ? "YES" : "NO") << endl;
}
