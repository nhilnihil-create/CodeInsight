/*  -*- coding: utf-8 -*-
 *
 * b.cc: B - Go to Jail
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
  int n;
  scanf("%d", &n);

  int c = 0;
  for (int i = 0; i < n; i++) {
    int d0, d1;
    scanf("%d%d", &d0, &d1);
    if (d0 == d1) {
      if (++c >= 3) {
	puts("Yes");
	return 0;
      }
    }
    else
      c = 0;
  }

  puts("No");
  return 0;
}
