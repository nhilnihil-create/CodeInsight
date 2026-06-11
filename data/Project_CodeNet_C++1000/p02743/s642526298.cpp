#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a,b,c; cin >> a >> b >> c;
  string ans = "No";
  if ((c-a-b) > 0 && 4*a*b < (c-a-b)*(c-a-b)) ans = "Yes";
  cout << ans << endl;
  return 0;
}