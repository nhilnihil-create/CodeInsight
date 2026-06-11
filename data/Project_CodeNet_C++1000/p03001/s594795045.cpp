

#include <bits/stdc++.h>

#define loop(s, e, i) for (int i=s; i<e; ++i)
#define print(s) cout << s << endl;
using namespace std;
using ll = long long;


int main() {
  double W, H, x, y;
  cin >> W >> H >> x >> y;

  double res1 = W*H/2;
  int res2 = (W == x+x) && (H == y+y);
  cout << fixed << setprecision(9) << res1 << ' ' << res2 << endl;
}