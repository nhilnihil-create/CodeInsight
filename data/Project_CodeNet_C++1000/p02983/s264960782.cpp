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
  LL L, R; cin >> L >> R;
  LL dL = L/2019LL, dR = R/2019LL;
  if (dL != dR) {
    cout << 0 << endl;
    return 0;
  }

  LL L2 = L % 2019, R2 = R % 2019;
  LL vmin = 1e18;
  for (LL i = L2; i <= R2; ++i) {
    for (LL j = i + 1LL; j <= R2; ++j) {
      LL v = (i * j) % 2019;
      vmin = min(v, vmin);
    }
  }

  cout << vmin << endl;
}
