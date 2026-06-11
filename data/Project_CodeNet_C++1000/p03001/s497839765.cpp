#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int W, H, X, Y;
  cin >> W >> H >> X >> Y;
  bool bl = (X * 2 == W && Y * 2 == H);
  double ans = (double) W * H / 2;
  printf("%.10f ", ans);
  puts(bl ? "1" : "0");
  return 0;
}