/*  -*- coding: utf-8 -*-
 *
 * c.cc: C - A x B &#43; C
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

const int MAX_N = 1000000;

/* typedef */

/* global variables */

int cs[MAX_N];

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i < n; i++)
    for (int j = i; j < n; j += i) cs[j]++;

  int sum = 0;
  for (int i = 1; i < n; i++) sum += cs[i];

  printf("%d\n", sum);
  return 0;
}
