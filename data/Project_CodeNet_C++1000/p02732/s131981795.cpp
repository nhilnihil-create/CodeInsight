
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int vs[200000+10];
ll hs[200000+10];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &vs[i]);
    hs[vs[i]]++;
  }
  ll total = 0;
  REP(i, n) {
    total += hs[i+1] * (hs[i+1]-1) / 2;
  }
  REP(i, n) {
    int v = vs[i];
    ll h = hs[v];
    total -= h * (h-1) / 2;
    --h;
    total += h * (h-1) / 2;
    printf("%lld\n", total);
    total -= h * (h-1) / 2;
    ++h;
    total += h * (h-1) / 2;
  }
  return 0;
}
