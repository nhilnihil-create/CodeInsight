#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;


ll attack(ll x) {
    if (x == 1) return 1;
    else {
      x = x/2;
      return 2 * attack(x) + 1;
    }
}
int main() {
  ll H; cin >> H;

  ll ans = attack(H);
  cout << ans << endl;
	return 0;
}

