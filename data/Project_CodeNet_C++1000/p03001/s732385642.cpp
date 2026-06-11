#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll W, H, x, y;
  cin >> W >> H >> x >> y;
  int dup = 0;
  if (x*2==W && y*2==H) dup = 1;
  auto ans = W*H/2.0;
  cout << fixed << setprecision(10) << ans;
  cout << " " << dup << endl;
  return 0;
}