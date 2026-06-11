/*
 * b.cc: 
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
  for (;;) {
    int h, w;
    cin >> h >> w;
    if (h == 0) break;

    for (int y = 0; y < h; y++) {
      if (y == 0 || y == h - 1) {
	for (int x = 0; x < w; x++) putchar('#');
      }
      else {
	putchar('#');
	for (int x = 0; x < w - 2; x++) putchar('.');
	putchar('#');
      }
      putchar('\n');
    }
    putchar('\n');
  }

  return 0;
}