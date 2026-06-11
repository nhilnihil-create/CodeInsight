/*
 * a.cc: 
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
    int m, f, r;
    cin >> m >> f >> r;
    if (m < 0 && f < 0 && r < 0) break;

    char ans;
    if (m < 0 || f < 0) ans = 'F';
    else {
      int sum = m + f;
      if (sum >= 80) ans = 'A';
      else if (sum >= 65) ans = 'B';
      else if (sum >= 50) ans = 'C';
      else if (sum >= 30) {
	if (r >= 50) ans = 'C';
	else ans = 'D';
      }
      else ans = 'F';
    }

    printf("%c\n", ans);
  }
  
  return 0;
}