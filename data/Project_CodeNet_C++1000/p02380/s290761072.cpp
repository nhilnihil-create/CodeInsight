/*
 * b.cc: 
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

const double PI = acos(-1.0);

/* typedef */

/* global variables */

/* subroutines */

/* main */

int main() {
  double a, b, c;
  cin >> a >> b >> c;

  double th = PI * c / 180;

  double h = b * sin(th);
  double s = 0.5 * a * h;
  double l = sqrt(a * a + b * b - 2.0 * a * b * cos(th)) + a + b;

  printf("%.8lf\n", s);
  printf("%.8lf\n", l);
  printf("%.8lf\n", h);

  return 0;
}