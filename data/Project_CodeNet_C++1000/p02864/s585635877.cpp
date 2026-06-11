/*  -*- coding: utf-8 -*-
 *
 * f.cc: F - Laminate
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

const int MAX_N = 300;
const long long LINF = 1LL << 62;

/* typedef */

typedef long long ll;

/* global variables */

int hs[MAX_N + 1];
ll dp[MAX_N + 1][MAX_N + 1];

/* subroutines */

inline void setmin(ll &a, ll b) { if (a > b) a = b; }

/* main */

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  hs[0] = 0;
  for (int i = 1; i <= n; i++) scanf("%d", hs + i);

  int m = n - k;
  for (int i = 0; i <= m; i++)
    fill(dp[i], dp[i] + n + 1, LINF);
  dp[0][0] = 0;

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (dp[i][j] < LINF)
	for (int j1 = j + 1; j1 <= n; j1++)
	  setmin(dp[i + 1][j1], dp[i][j] + max(0, hs[j1] - hs[j]));

  ll mind = LINF;
  for (int j = 0; j <= n; j++) setmin(mind, dp[m][j]);

  printf("%lld\n", mind);
  return 0;
}
