/*
 * c.cc: 
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
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) break;

    if (x > y) swap(x, y);
    printf("%d %d\n", x, y);
  }

  return 0;
}