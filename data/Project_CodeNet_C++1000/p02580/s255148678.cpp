#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define rep(i,N) for(int i=0;i<(int)N;i++)
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
static inline void PUT(char c)
{
  static char buf[1<<15],*ptr=buf;
  if(ptr==buf+strlen(buf)||c==0){fwrite(buf,1,ptr-buf,stdout),ptr=buf;}*ptr++=c;
}
static inline int IN(void)
{
  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}
  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;
}
static inline void OUT(int a)
{
  if(a<0)PUT('-'),a=-a;
  int d[40],i=0;do{d[i++]=a%10;}while(a/=10);
  while(i--){PUT(d[i]+48);}PUT('\n');
}
static inline int Max(int x,int y){return x>y?x:y;}
int main(void)
{
  int H=IN(),W=IN(),M=IN(),row[H]={0},col[W]={0},bomb[300000][2],
  destroy=0,idh=0,idw=0,hmax=0,wmax=0,hsz=0,wsz=0,obj=0;
  rep(i,M)
  {
    bomb[i][0]=IN()-1,bomb[i][1]=IN()-1;
    row[bomb[i][0]]++;col[bomb[i][1]]++;
    hmax=Max(hmax,row[bomb[i][0]]);wmax=Max(wmax,col[bomb[i][1]]);
  }
  rep(i,H){if(hmax==row[i]){idh++;}}rep(j,W){if(wmax==col[j]){idw++;}}
  destroy=hmax+wmax;
  rep(i,M){if(row[bomb[i][0]]==hmax&&col[bomb[i][1]]==wmax){obj++;}}
  return OUT(1l*obj==1l*idh*idw?destroy-1:destroy),0;
}