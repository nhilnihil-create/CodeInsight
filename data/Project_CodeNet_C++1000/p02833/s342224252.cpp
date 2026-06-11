#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

ll fact(ll n, int p){
  if (n == 0) return 0;
  return n/p + fact(n/p,p);
}

ll fact2(ll n, int p) {
  if (n % 2 == 1) return fact(n,p) - fact(n-1,p);
  if (p == 2) return fact(n/2, p) + n/2;
  return fact(n/2, p);
}

int main() {
  ll n;
  cin >> n;

  if (n % 2 != 0){
    cout << 0 << endl;
    return 0;
  }

  ll ans = min(fact2(n, 2), fact2(n,5));
  cout << ans << endl;
  return 0;
}
