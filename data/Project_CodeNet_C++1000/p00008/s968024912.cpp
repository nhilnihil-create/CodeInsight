#include <cstdio>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)

int main() {
  int n;
  while(scanf("%d",&n) != EOF) {
    int t = 0;
    REP(i,10) {
      if(i > n) break;
      REP(j,10) {
	if(i+j > n) break;
	REP(k,10) {
	  if(i+j+k > n) break;
	  REP(l,10) {
	    if(i+j+k+l > n) break;
	    else if(i+j+k+l == n) t += 1;
	  }
	}
      }
    }
    printf("%d\n", t);
  }

  return 0;
}