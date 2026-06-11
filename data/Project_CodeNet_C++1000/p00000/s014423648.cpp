#include <stdio.h>

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

int main()
{
  FOR(i,1,10) {
    FOR(j,1,10) {
      printf("%dx%d=%d\n",i,j,i*j);
    }
  }
  return 0;
}
