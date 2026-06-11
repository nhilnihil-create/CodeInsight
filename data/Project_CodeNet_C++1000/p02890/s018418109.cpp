#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
#define MAXN 300000
int n,cnt[MAXN+5],ans[MAXN+5];
LL sum[MAXN+5];
LL read(){
  LL x=0,F=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
  return x*F;
}
int main()
{
  n=read();
  for(int i=1;i<=n;i++){
    int x=read();
    cnt[x]++,sum[cnt[x]]++;
  }
  for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
  int t=0;
  for(int k=n;k>=1;k--){
    while(t<n&&sum[t+1]>=1LL*k*(t+1))t++;
    ans[k]=t;
  }
  for(int i=1;i<=n;i++)
  printf("%d\n",ans[i]);
}
