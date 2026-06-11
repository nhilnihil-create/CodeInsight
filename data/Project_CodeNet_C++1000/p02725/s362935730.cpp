#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define repi(n) for (long long i = 0; i < (n); ++i)
#define repj(n) for (long long j = 0; j < (n); ++j)
#define repk(n) for (long long k = 0; k < (n); ++k)
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(itr) for (auto&& v : (itr))
#define updatemax(t, v) (t = std::max(t, (v)))
#define updatemin(t, v) (t = std::min(t, (v)))

ll a[1000100];
int main() {
  ll k, n;
  cin >> k >> n;
  repi(n) cin >> a[i];
  sort(a, a + n);
  ll re = a[n - 1] - a[0];
  repi(n - 1) updatemin(re, k - (a[i + 1] - a[i]));
  cout << re << endl;
}
