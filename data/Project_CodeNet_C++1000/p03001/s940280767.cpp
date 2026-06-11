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
  LL W, H, x, y; cin >> W >> H >> x >> y;
  double S = W * H;
  S /= 2;

  if (W % 2 == 1 || H % 2 == 1)
    printf("%.10f %d\n", S, 0);
  else if (W/2 != x || H/2 != y)
    printf("%.10f %d\n", S, 0);
  else
    printf("%.10f %d\n", S, 1);
}
