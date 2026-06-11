
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int vs[200000+10];

int main(void) {
  int K, N;
  scanf("%d%d", &K, &N);
  REP(i, N) {
    scanf("%d", &vs[i]);
  }
  int maxi = vs[0] + K - vs[N-1];
  REP(i, N-1) {
    maxi = max(maxi, vs[i+1] - vs[i]);
  }
  cout << K - maxi << endl;
  return 0;
}
