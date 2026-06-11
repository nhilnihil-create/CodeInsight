#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  double a, b, x; cin >> a >> b >> x;
  double rad1 = atan2(2*a*a*b - 2*x, a*a*a);
  double rad2 = atan2(a*b*b, 2*x);

  if (b > a * tan(rad1)) {
    printf("%.8f\n", rad1 * 180 / M_PI);
  } else {
    printf("%.8f\n", rad2 * 180 / M_PI);
  }
}
