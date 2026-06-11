#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

int hist[200000+5];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n-1) {
    int v;
    scanf("%d", &v);
    --v;
    hist[v]++;
  }
  REP(i, n) {
    printf("%d\n", hist[i]);
  }
  return 0;
}
