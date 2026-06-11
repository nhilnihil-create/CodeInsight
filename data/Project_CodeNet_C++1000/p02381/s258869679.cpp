/*
 * c.cc: 
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

const int MAX_N = 1000;

/* typedef */

/* global variables */

int as[MAX_N];

/* subroutines */

/* main */

int main() {
  for (;;) {
    int n;
    cin >> n;
    if (n == 0) break;

    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> as[i];
      sum += as[i];
    }

    double m = (double)sum / n;
    double sg2 = 0.0;

    for (int i = 0; i < n; i++) {
      double d = (double)as[i] - m;
      sg2 += d * d;
    }

    printf("%.8lf\n", sqrt(sg2 / n));
  }
  return 0;
}