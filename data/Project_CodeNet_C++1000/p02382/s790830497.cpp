/*
 * d.cc: 
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

const int MAX_N = 100;

/* typedef */

/* global variables */

double xs[MAX_N], ys[MAX_N];

/* subroutines */

/* main */

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> xs[i];
  for (int i = 0; i < n; i++) cin >> ys[i];

  double sum1 = 0.0, sum2 = 0.0, sum3 = 0.0, maxd = 0.0;

  for (int i = 0; i < n; i++) {
    double d = abs(xs[i] - ys[i]);
    sum1 += d;
    sum2 += d * d;
    sum3 += d * d * d;
    if (maxd < d) maxd = d;
  }

  printf("%.6lf\n", sum1);
  printf("%.6lf\n", sqrt(sum2));
  printf("%.6lf\n", pow(sum3, 1.0 / 3));
  printf("%.6lf\n", maxd);

  return 0;
}