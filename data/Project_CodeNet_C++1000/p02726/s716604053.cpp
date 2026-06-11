
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int N, X, Y;
inline int dist(int a, int b) {
  return min(min(abs(b-a), abs(a-X) + 1 + abs(b-Y)), abs(a-Y) + 1 + abs(b-X));
}

int hist[2020];

int main(void) {
  scanf("%d%d%d", &N, &X, &Y);
  --X;
  --Y;
  REP(i, N) REP(j, i) {
    hist[dist(i, j)]++;
  }

  for(int k = 1; k < N; ++k) {
    printf("%d\n", hist[k]);
  }
  return 0;
}
