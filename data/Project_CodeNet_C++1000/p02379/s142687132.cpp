/*
 * a.cc: 
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>

using namespace std;

/* constant */

/* typedef */

/* global variables */

/* subroutines */

/* main */

int main() {
  double x0, y0, x1, y1;
  cin >> x0 >> y0 >> x1 >> y1;

  double dx = x1 - x0, dy = y1 - y0;
  printf("%.8lf\n", sqrt(dx * dx + dy * dy));
  return 0;
}