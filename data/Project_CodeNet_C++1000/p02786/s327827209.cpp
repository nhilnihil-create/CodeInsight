#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll h; cin >> h;
  ll ans = 1;
  while(h!=0) {
    h/=2;
    ans *= 2;
  }
  cout << ans - 1 << endl;
  return 0;
}