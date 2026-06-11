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
  double N; cin >> N;
  LL cnt = 0;
  for (LL A = 1; A < N; ++A) {
    LL bs = ceil(N/A) - 1;
    cnt += bs;
  }
  cout << cnt << endl;
}
