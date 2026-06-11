#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b; cin >> a >> b;
  int ans = -1;
  int al = a*100+4, bl = b*100+5;
  if (max(al/8, bl/10) < min((al+100)/8,(bl+100)/10)) ans = max(al/8,bl/10);
  cout << ans << endl;
  return 0;
}