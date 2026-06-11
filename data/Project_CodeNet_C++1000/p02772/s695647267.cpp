
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
  int n;
  cin >> n;
  bool ok = true;
  REP(i, n) {
    int v;
    cin >> v;
    if(v % 2 == 0 && (v % 3 != 0 && v % 5 != 0)) {
      ok = false;
    }
  }
  if(ok) {
    puts("APPROVED");
  } else {
    puts("DENIED");
  }
  return 0;
}
