/*  -*- coding: utf-8 -*-
 *
 * f.cc: F - Distinct Numbers
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

const int MAX_N = 300000;

/* typedef */

typedef long long ll;

/* global variables */

int cs[MAX_N + 1], ds[MAX_N + 1];
int dss[MAX_N + 1], kdss[MAX_N + 1];
int fs[MAX_N + 1];

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    cs[ai]++;
  }

  for (int i = 1; i <= n; i++) ds[cs[i]]++;
  //for (int i = 1; i <= n; i++) printf("%d ", ds[i]); putchar('\n');

  dss[0] = kdss[0] = 0;
  for (int i = 1; i <= n; i++) {
    dss[i] = dss[i - 1] + ds[i];
    kdss[i] = kdss[i - 1] + i * ds[i];
  }

  for (int i = 1; i <= n; i++) {
    fs[i] = (kdss[i] + (ll)i * (dss[n] - dss[i])) / i;
    //printf("fs[%d] = (%d+%d*(%d-%d))/%d = %d\n",
    //i, kdss[i], i, dss[n], dss[i], i, fs[i]);
  }

  for (int i = 1, j = n; i <= n; i++) {
    while (j > 0 && fs[j] < i) j--;
    printf("%d\n", j);
  }
  return 0;
}
