#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  int ans = -1;
  rep(i,n+1) {
    if (n == i * 108/100) {
      ans = i;
      break;
    }
  }
  if (ans == -1) {
    cout << ":(" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}