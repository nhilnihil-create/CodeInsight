/*
 * d.cc: 
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
  string s, p;
  cin >> s >> p;

  int sn = s.size(), pn = p.size();

  for (int i = 0; i < sn; i++) {
    bool ok = true;
    for (int j = 0; j < pn; j++)
      if (s[(i + j) % sn] != p[j]) {
	ok = false;
	break;
      }
    if (ok) {
      puts("Yes");
      return 0;
    }
  }

  puts("No");
  return 0;
}