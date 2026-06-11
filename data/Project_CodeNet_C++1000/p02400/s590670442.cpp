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
  double r;
  cin >> r;

  printf("%.6lf %.6lf\n", PI * r * r, PI * 2 * r);
  return 0;
}