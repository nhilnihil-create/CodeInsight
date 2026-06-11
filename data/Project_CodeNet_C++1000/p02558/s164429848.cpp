/*  -*- coding: utf-8 -*-
 *
 * a.cc: A - Disjoint Set Union
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

struct UFT {
  int links[MAX_N], ranks[MAX_N], sizes[MAX_N];
  UFT() {}

  void init(int n) {
    for (int i = 0; i < n; i++) links[i] = i, ranks[i] = sizes[i] = 1;
  }

  int root(int i) {
    int i0 = i;
    while (links[i0] != i0) i0 = links[i0];
    return (links[i] = i0);
  }

  int rank(int i) { return ranks[root(i)]; }
  int size(int i) { return sizes[root(i)]; }
  bool same(int i, int j) { return root(i) == root(j); }

  int merge(int i0, int i1) {
    int r0 = root(i0), r1 = root(i1), mr;
    if (r0 == r1) return r0;
    if (ranks[r0] == ranks[r1]) {
      links[r1] = r0;
      sizes[r0] += sizes[r1];
      ranks[r0]++;
      mr = r0;
    }
    else if (ranks[r0] > ranks[r1]) {
      links[r1] = r0;
      sizes[r0] += sizes[r1];
      mr = r0;
    }
    else {
      links[r0] = r1;
      sizes[r1] += sizes[r0];
      mr = r1;
    }
    return mr;
  }
};

/* global variables */

UFT uft;

/* subroutines */

/* main */

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  uft.init(n);

  while (q--) {
    int op, u, v;
    scanf("%d%d%d", &op, &u, &v);

    if (op == 0)
      uft.merge(u, v);
    else
      printf("%d\n", uft.same(u, v) ? 1 : 0);
  }
  return 0;
}
