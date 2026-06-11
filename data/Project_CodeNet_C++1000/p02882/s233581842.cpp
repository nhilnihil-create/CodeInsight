#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  long double a, b, x;
  cin >> a >> b >> x;
  // cout << b << " " << x << " " << a << endl;
  if (x < a * a * b / 2.0) {
    long double y = (2 * x) / (a * b);
    long double theta = atan(y / b) * 180.0 / M_PI;
    cout << fixed << setprecision(10) << 90.0 - theta << endl;
  } else {
    long double y = 2 * b - (2 * x) / (a * a);
    long double theta = atan(y / a) * 180 / M_PI;
    cout << fixed << setprecision(10) << theta << endl;
  }
  return 0;
}