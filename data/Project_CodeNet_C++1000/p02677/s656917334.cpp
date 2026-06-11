#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>
#include <string>
#include <cassert>
#include <bitset>

using namespace std;
typedef long long ll;

void Calc(int A, double theta, double &x, double &y) {
  x = A * cos(theta);
  y = A * sin(theta);
}

int main() {
  int A, B, H, M;
  cin >> A >> B >> H >> M;
  double theta1 = 2.0 * M_PI * (double(H) + double(M) / 60.0) / 12.0;
  double theta2 = 2.0 * M_PI * double(M) / 60.0;
  double x1, y1, x2, y2;
  Calc(A, theta1, x1, y1);
  Calc(B, theta2, x2, y2);
  double dx = x1 - x2;
  double dy = y1 - y2;
  double dist = sqrt(dx * dx + dy * dy);
  cout << setprecision(20);
  cout << dist << endl;
  return 0;
}
