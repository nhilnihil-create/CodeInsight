#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

const double PI = atan2(0, -1);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
  int a, b, x;
  cin >> a >> b >> x;
  int v = a * a * b;
  double ans, tg;
  if (x * 2 >= v) {
    int delta = v - x;
    tg = (double)2 * delta / (a * a * a);
  } else {
    double c = (double)2 * x / (b * a);
    tg = b / c;
  }
  ans = atan(tg);
  ans *= (double)180 / PI;
  cout << ans << '\n';
}