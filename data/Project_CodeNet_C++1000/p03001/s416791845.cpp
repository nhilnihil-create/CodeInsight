#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  double W, H; cin >> W >> H;
  double x, y; cin >> x >> y;
  
  cout << fixed << setprecision(10) << W*H/2 << " ";
  if(x == W/2 && y == H/2) cout << 1 << endl;
  else cout << 0 << endl;
}