#include<stdio.h>
#pragma GCC optimize("O2")
#define swap(a,b) (a+=b,b=a-b,a-=b)
static inline char CH()
{
  static char buf[100000],*ptr1=buf,*ptr2=buf;
  return ptr1==ptr2&&(ptr2=(ptr1=buf)+fread(buf,1,100000,stdin),ptr1==ptr2)?EOF:*ptr1++;
}
static inline int IN(void)
{
  int x=0,f=0,c=CH();while(c<48||c>57){f^=c==45,c=CH();}
  while(c>47&&c<58){x=x*10+c-48,c=CH();}return f?-x:x;
}
int main(void)
{
  int N=IN(),i=0,u,v;long x=N;
  while(i++<N-1){u=IN(),v=IN();if(u>v){swap(u,v);}x+=1l*(i+1)*(N-i)-1l*u*(N+1-v);}
  return printf("%ld",x),0;
}