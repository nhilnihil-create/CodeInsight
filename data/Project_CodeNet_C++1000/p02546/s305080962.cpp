/*  -*- coding: utf-8 -*-
 *
 * a.cc: A - Plural Form
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

const int MAX_N = 1000;

/* typedef */

/* global variables */

char s[MAX_N + 4];

/* subroutines */

/* main */

int main() {
  scanf("%s", s);
  int n = strlen(s);

  if (s[n - 1] == 's') printf("%ses", s);
  else printf("%ss\n", s);
  return 0;
}
