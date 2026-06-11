/*  -*- coding: utf-8 -*-
 *
 * b.cc: B - Fenwick Tree
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

const int MAX_N = 500000;

/* typedef */

typedef long long ll;

template <typename T, const int MAX_N>
struct BIT {
  int n;
  T bits[MAX_N + 1];
  
  BIT() {}
  BIT(int _n) { init(_n); }

  void init(int _n) {
    n = _n;
    memset(bits, 0, sizeof(bits));
  }

  T sum(int x) {
    T s = 0;
    while (x > 0) {
      s += bits[x];
      x -= (x & -x);
    }
    return s;
  }

  void add(int x, T v) {
    while (x <= n) {
      bits[x] += v;
      x += (x & -x);
    }
  }
};

/* global variables */

BIT<ll,MAX_N> bit;

/* subroutines */

/* main */

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  bit.init(n);

  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    bit.add(i + 1, ai);
  }

  while (q--) {
    int op, p, x;
    scanf("%d%d%d", &op, &p, &x);

    if (op == 0)
      bit.add(p + 1, x);
    else
      printf("%lld\n", bit.sum(x) - bit.sum(p));
  }
  return 0;
}
