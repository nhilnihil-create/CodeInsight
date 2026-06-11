#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define erep(i, n) for(ll i = 1; i <= (n); i++)
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  int p, q, r;
  cin >> p >> q >> r;
  int ans=min({p+q,q+r,r+p});
  cout << ans << '\n';
  return 0;
}