#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x; cin >> x;
  int ans = 1;
  int xn = x/100;
  if (xn < 20 && x%100 > xn*5) ans = 0;
  cout << ans << endl;
  return 0;
}