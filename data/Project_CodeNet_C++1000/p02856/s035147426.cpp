#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define rrep(i, a, b) for (int i = int(a) - 1; i >= b; i--)
#define sz(x) (int)(x).size()

using namespace std;
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main() {
  ll m;
  cin >> m;
  vector<ll> d(m), c(m);
  ll sumc = 0, sumdc = 0;
  rep(i, 0, m) {
    cin >> d[i] >> c[i];
    sumc += c[i];
    sumdc += d[i] * c[i];
  }
  cout << (sumc - 1) + (sumdc - 1) / 9 << endl;
}
