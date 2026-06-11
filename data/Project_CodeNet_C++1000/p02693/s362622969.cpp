#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1000000009;
const ll LINF = 1e18;

int main() {
  int k, a, b;
  cin >> k >> a >> b;
  for (int i = a; i <= b; ++i) {
    if (i % k != 0) continue;
    cout << "OK\n";
    return 0;
  }
  cout << "NG\n";
  return 0;
}
