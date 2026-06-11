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

ll a[200100], ss[200100];
int main() {
  ll n, k;
  cin >> n >> k;
  repi(n) cin >> a[i];
  repi(n)-- a[i];
  repi(n) ss[i] = -1;
  ll current = 0;
  repi(n + 1) {
    ss[current] = i;
    current = a[current];
    if (ss[current] != -1) {
      ll pres = ss[current];
      ll looplen = (i + 1) - pres;
      if (k >= pres) k = pres + ((k - pres) % looplen);
      break;
    }
  }
  current = 0;
  repi(k) current = a[current];
  cout << current + 1 << endl;
}
