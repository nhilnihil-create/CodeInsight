
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

bool calc(int a, int b, int c) {
  return a == b && b != c;
}

int main(void) {
  int a, b, c;
  cin >> a >> b >> c;
  if(calc(a,b,c) || calc(b,c,a) || calc(c,a,b)) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}
