#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, a, b; cin >> n >> a >> b;
  ll m = (a+b)/2, ans = 0;
  ans = max(abs(a-m),abs(b-m));
  if ((b-a)%2 == 1) ans += min(abs(1-a),abs(n-b));
  cout << ans << endl;
  return 0;
}