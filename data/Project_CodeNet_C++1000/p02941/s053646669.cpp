/*  -*- coding: utf-8 -*-
 *
 * c.cc: C - Numbers on a Circle
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

const int MAX_N = 200000;

/* typedef */

typedef long long ll;
typedef pair<int,int> pii;

/* global variables */

int as[MAX_N], bs[MAX_N];

/* subroutines */

inline int prvi(int n, int i) { return ((i - 1 + n) % n); }
inline int nxti(int n, int i) { return ((i + 1) % n); }

inline bool check(int n, int i) {
  return (bs[i] > as[i] && bs[i] > bs[prvi(n, i)] + bs[nxti(n, i)]);
}

/* main */

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", as + i);
  for (int i = 0; i < n; i++) scanf("%d", bs + i);

  priority_queue<pii> q;
  for (int i = 0; i < n; i++)
    if (check(n, i)) q.push(pii(bs[i] - as[i], i));

  ll cnt = 0;
  while (! q.empty()) {
    pii u = q.top(); q.pop();
    int &ud = u.first, &ui = u.second;
    if (ud != bs[ui] - as[ui]) continue;

    int i0 = prvi(n, ui), i1 = nxti(n, ui);
    int ac = bs[i0] + bs[i1];
    int k = min(ud / ac, (bs[ui] - 1) / ac);
    if (k > 0) {
      cnt += k;
      bs[ui] -= k * ac;
      if (check(n, i0)) q.push(pii(bs[i0] - as[i0], i0));
      if (check(n, i1)) q.push(pii(bs[i1] - as[i1], i1));
    }
  }

  for (int i = 0; i < n; i++)
    if (bs[i] != as[i]) {
      puts("-1");
      return 0;
    }

  printf("%lld\n", cnt);
  return 0;
}
