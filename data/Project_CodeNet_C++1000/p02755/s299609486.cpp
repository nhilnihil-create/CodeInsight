#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b; cin >> a >> b;
  int ans = -1;
  rep(i,1000) {
    if (((i+1)*8)/100 == a && ((i+1)*10)/100 == b) {
      ans = i+1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}