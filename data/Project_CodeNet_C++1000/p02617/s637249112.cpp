#include<stdio.h>
#pragma GCC optimize("O3")
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


int main(){
    int n=IN(),i=0,u,v;
    long x = n;
    long a = x*(x+1)*(x+2)/6;
    while(i++ < n-1){
        u=IN();
        v=IN();
        if(u<v){
            a -= 1l * u * (n-v+1);
        }else{
            a -= 1l * v * (n-u+1);
        }
    }
    return printf("%ld", a), 0;
}
