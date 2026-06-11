#include<stdio.h>
#pragma GCC optimize("O2")
static inline int comp(const int a,const int b,int desc){return a<b?(!desc?a:b):(!desc?b:a);}
int main(void)
{
  int N,i=scanf("%d",&N)-1,u,v;long x=1l*N*(N+1)*(N+2)/6;
  while(i<N-1){i+=scanf("%d %d",&u,&v)>>1;x=x-1l*comp(u,v,0)*(N-comp(u,v,1)+1);}
  return printf("%ld",x),0;
}