#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <set>
#include <random>
using namespace std;

int main() {
  int X, Y;
  cin >> X >> Y;
  int ans = max(4 - X, 0) + max(4 - Y, 0);
  ans += 4 * (ans == 6);
  cout << ans * 100000 << endl;
  return 0;
}
