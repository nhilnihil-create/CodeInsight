/*  -*- coding: utf-8 -*-
 *
 * f.cc: F - Many Slimes
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

const int MAX_N = 18;
const int MAX_M = 1 << MAX_N;

/* typedef */

typedef pair<int,int> pii;
typedef multiset<int> msi;

/* global variables */

int as[MAX_M], vs[MAX_M];
msi xset;

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);
  int m = 1 << n;

  for (int i = 0; i < m; i++) scanf("%d", as + i);
  sort(as, as + m);

  xset.insert(m);

  for (int i = m - 1; i >= 0;) {
    int k = 1;
    while (k <= i && as[i] == as[i - k]) k++;
    i -= k;

    if (xset.size() < k) {
      puts("No");
      return 0;
    }

    msi::iterator mit = xset.end();
    for (int j = 0; j < k; j++) vs[j] = *(--mit);
    xset.erase(mit, xset.end());

    for (int j = 0; j < k; j++)
      for (int b = 1; b < vs[j]; b <<= 1) xset.insert(b);
  }

  puts("Yes");
  return 0;
}
