#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
  double A, B, H, M;
  cin >> A >> B >> H >> M;
  double anglem = 6.0 * M;
  double angleh = 30.0 * (H + M / 60.0);
  double diffangle = abs(anglem - angleh);
  double c = A * A + B * B - 2.0 * A * B * cos(diffangle / 180.0 * acos(-1.0));
  printf("%.15f\n", sqrt(c));
  return 0;
}