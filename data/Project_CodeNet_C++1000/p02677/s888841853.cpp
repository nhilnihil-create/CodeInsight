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
  double A, B, H, M; cin >> A >> B >> H >> M;
  double H2 = H / 12;
  double M2 = M / 60;

  double th_h = 2 * M_PI * (H2 + M2/12);
  double th_m = 2 * M_PI * M2;
  double th = abs(th_h - th_m);

  double C2 = A * A + B * B - 2 * A * B * cos(th);
  printf("%.20f\n", sqrt(C2));
}
