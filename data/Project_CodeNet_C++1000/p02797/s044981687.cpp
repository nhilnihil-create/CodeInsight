#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n, m, l;
  cin >> n >> m >> l;
  rep(i, n) {
    ll res;
    if (i < m) res = l;
    else {
      if (l < 100) res = l+1;
      else res = l-1;
    }
    if (i) cout << ' ' << res;
    else cout << res;
  }
  cout << endl;
}