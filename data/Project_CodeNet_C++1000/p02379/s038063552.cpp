#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  printf("%f\n", sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
  return 0;
}
