#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x; cin >> x;
  int r = 8;
  for (int i = 600; i<= 1800; i += 200) {
    if (x < i) {
      break;
    }
    r--;
  }
  cout << r << endl;
  return 0;
}
