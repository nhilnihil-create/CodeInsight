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

double rad2deg(double rad) { return (((rad)/2/M_PI)*360); }
int main() {
  double a, b, x; cin >> a >> b >> x;
  double rad;
  if (a * a * b / 2.0 <= x) {
    rad = atan2(2 * (a * a * b - x), a * a * a);
  } else {
    rad = M_PI/2 - atan2(2*x, a*b*b);
  }
  printf("%.9f\n", rad2deg(rad));
}
