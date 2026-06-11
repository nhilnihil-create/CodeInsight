/*  -*- coding: utf-8 -*-
 *
 * f.cc: F - Engines
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
const int MAX_N2 = MAX_N * 2;
const double PI = acos(-1.0);

/* typedef */

typedef long long ll;

struct TVec {
  double th;
  int x, y;
  TVec() {}
  TVec(double _th, int _x, int _y): th(_th), x(_x), y(_y) {}
  bool operator<(const TVec &tv) const { return th < tv.th; }
};

/* global variables */

TVec tvs[MAX_N2];

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    tvs[i] = TVec(atan2(y, x), x, y);
  }

  sort(tvs, tvs + n);
  for (int i = 0; i < n; i++) tvs[i + n] = tvs[i];

  ll maxd2 = 0;
  for (int i = 0; i < n; i++) {
    int xm = 0, ym = 0;
    for (int j = 0, k = i; j < n; j++, k++) {
      xm += tvs[k].x, ym += tvs[k].y;
      ll d2 = (ll)xm * xm + (ll)ym * ym;
      if (maxd2 < d2) maxd2 = d2;
    }
  }

  printf("%.12lf\n", sqrt((double)maxd2));
  return 0;
}
