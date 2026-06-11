
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int solve(int a, int b) {
  for(int x = 0; x <= 10000; ++x) {
    int ax = floor(x * 0.08);
    int bx = floor(x * 0.10);
    if(a == ax && b == bx) {
      return x;
    }
  }
  return -1;
}

int main(void) {
  int a, b;
  cin >> a >> b;
  int res = solve(a, b);
  cout << res << endl;
  return 0;
}
