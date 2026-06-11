/*  -*- coding: utf-8 -*-
 *
 * a.cc: A - DDCC Finals
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
  int x, y;
  scanf("%d%d", &x, &y);

  int sum = 0;
  if (x < 4) sum += (4 - x) * 100000;
  if (y < 4) sum += (4 - y) * 100000;
  if (x == 1 && y == 1) sum += 400000;

  printf("%d\n", sum);
  return 0;
}
