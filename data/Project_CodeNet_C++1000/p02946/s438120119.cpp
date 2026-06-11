#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  int k, x;
  cin >> k >> x;
  // [x-k, x+k]
  rep(i, x - k + 1, x + k) cout << i << endl;
  return 0;
}