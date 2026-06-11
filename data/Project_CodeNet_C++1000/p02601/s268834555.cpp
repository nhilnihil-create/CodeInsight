#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c, k; cin >> a >> b >> c >> k;
  string ans = "No";
  while (k > 0) {
    if (a >= b) b*=2;
    else break;
    k--;
  }
  while (k > 0) {
    if (b >= c) c*=2;
    else break;
    k--;
  }
  if (a < b && b < c) ans = "Yes";
  cout << ans << endl;
  return 0;
}