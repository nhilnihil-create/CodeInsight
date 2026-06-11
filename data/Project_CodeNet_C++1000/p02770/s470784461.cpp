/*  -*- coding: utf-8 -*-
 *
 * f.cc: F - Modularness
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

const int MAX_K = 5000;
const int MOD = 1000000007;

/* typedef */

typedef long long ll;

/* global variables */

int ds[MAX_K], zss[MAX_K + 1];
ll dss[MAX_K + 1];

/* subroutines */

/* main */

int main() {
  int k, q;
  scanf("%d%d", &k, &q);

  for (int i = 0; i < k; i++) scanf("%d", ds + i);

  while (q--) {
    int n, x, m;
    scanf("%d%d%d", &n, &x, &m);

    dss[0] = zss[0] = 0;
    for (int i = 0; i < k; i++) {
      int d = ds[i] % m;
      dss[i + 1] = dss[i] + d;
      zss[i + 1] = zss[i] + ((d == 0) ? 1 : 0);
    }

    ll sum = x % m + dss[k] * ((n - 1) / k) + dss[(n - 1) % k];
    int zn = zss[k] * ((n - 1) / k) + zss[(n - 1) % k];
    printf("%lld\n", (n - 1) - (zn + sum / m));
  }
  return 0;
}
