#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll W,H;
  cin >> W >> H;
  ll x,y;
  cin >> x >> y;
  int mode = 0;
  long double ans = (W * H) / 2.0;
  if (W % 2 == 0 && H % 2 == 0 && x == W/2 && y == H/2) {
    mode = 1;
  }
  cout << setprecision(120) << ans;
  cout << " " << mode << endl;
  return 0;
}