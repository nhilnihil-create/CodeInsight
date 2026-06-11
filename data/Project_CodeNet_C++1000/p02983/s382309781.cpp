#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int l, r; cin >> l >> r;
  const int INF = 2000000005;
  int ans = INF, cnt = 0;
  for (int i=l; i<=r; i++) {
    if (i%2019==0) {
      ans = 0;
      break;
    }
    for (int j=i%2019+1; j <= r%2019;j++) {
      ans = min((i%2019 * j%2019)%2019, ans);
    }
    if (cnt == 2019) break;
    cnt++;
  }
  cout << ans << endl;
  return 0;
}