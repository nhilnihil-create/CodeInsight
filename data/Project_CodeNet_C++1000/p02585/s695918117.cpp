/*  -*- coding: utf-8 -*-
 *
 * d.cc: D - Moving Piece
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

const int MAX_N = 5000;
const long long LINF = 1LL << 62;

/* typedef */

typedef long long ll;

/* global variables */

int ps[MAX_N], cs[MAX_N], q[MAX_N * 2];
bool used[MAX_N];
ll css[MAX_N * 2 + 1];

/* subroutines */

/* main */

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", ps + i), ps[i]--;
  for (int i = 0; i < n; i++) scanf("%d", cs + i);

  ll maxsum = -LINF;
  for (int st = 0; st < n; st++)
    if (! used[st]) {
      int m = 0;
      for (int u = st; ! used[u]; u = ps[u], m++) {
	used[u] = true;
	css[m + 1] = css[m] + cs[u];
      }
      for (int i = 0; i < m; i++) css[i + m + 1] = css[i + 1] + css[m];
      //for (int i = 0; i <= m * 2; i++) printf("%lld ", css[i]);
      //putchar('\n');

      int t = k / m, r = k % m;
      if (r == 0) t--, r = m;
      else if (t > 0 && css[m] <= 0) t = 0, r = m;

      ll maxd = -LINF;
      int qh = 0, qt = 0;
      for (int i = 0, j = 1; i < m; i++) {
	while (qh < qt && q[qh] <= i) qh++;
	while (j <= i + r) {
	  while (qh < qt && css[q[qt - 1]] <= css[j]) qt--;
	  q[qt++] = j++;
	}

	ll d = css[q[qh]] - css[i];
	if (maxd < d) maxd = d;
      }

      ll sum = maxd + css[m] * t;
      if (maxsum < sum) maxsum = sum;
    }

  printf("%lld\n", maxsum);
  return 0;
}
