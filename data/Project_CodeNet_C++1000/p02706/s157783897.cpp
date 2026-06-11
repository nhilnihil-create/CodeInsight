#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

const double PI = acos(-1);

int main(void) {
  int N, M;
  cin >> N >> M;
  REP(i, M) {
    int v;
    cin >> v;
    N -= v;
  }
  printf("%d\n", N >= 0 ? N : -1);
  return 0;
}
