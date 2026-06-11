#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

vector<vector<ll>> a(501, vector<ll>(501, -1));

signed main() {
  ll N, k=0, bit=1;
  cin >> N;
  for (; bit<N; bit <<= 1, k++) {
    rep(i,N) rep(j,N) {
      if ((i&bit) != (j&bit)) {
        a[i][j] = a[j][i] = k+1;
      }
    }
  }
  rep(i,N-1) {
    for (ll j=i+1; j<N; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}
