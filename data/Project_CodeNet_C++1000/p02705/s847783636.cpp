#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

const double PI = acos(-1);

int main(void) {
  double r;
  cin >> r;
  printf("%.10f\n", 2*PI*r);
  return 0;
}
