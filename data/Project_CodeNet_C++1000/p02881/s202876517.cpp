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
  LL N; cin >> N;
  LL vmin = 1e18;
  for (LL i = 1; i * i <= N; ++i) {
    if (N % i  == 0) {
      LL j = N / i;
      vmin = min(vmin, (i + j - 2));
    }
  }
  cout << vmin << endl;
}
