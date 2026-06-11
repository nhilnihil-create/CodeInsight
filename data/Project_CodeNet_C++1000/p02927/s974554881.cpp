#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (ll i=(a); i<(b); ++i)
inline ll in() { ll x; cin >> x; return x; }

int main() {
  int m = in(), d = in();
  int ans = 0;
  FOR(i,22,d+1) {
    int d1 = i % 10, d10 = i / 10;
    if (d1<2 || d10<2) continue;
    if (d1*d10<=m) ans++;
  }
  cout << ans << endl;
  return 0;
}
