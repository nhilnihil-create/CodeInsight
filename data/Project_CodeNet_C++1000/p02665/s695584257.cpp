#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

int n,a[N+9];

int main(){
  scanf("%d",&n);
  LL sum=0;
  for (int i=0;i<=n;++i){
	scanf("%d",&a[i]);
	sum+=a[i];
  }
  if (n==0) {puts(a[0]==1?"1":"-1");return 0;}
  if (a[0]) {puts("-1");return 0;}
  LL now=1,ans=1;
  for (int i=1;i<=n;++i){
	ans+=now=min(now<<1,sum);
	if ((now-=a[i])<0) {puts("-1");return 0;}
	sum-=a[i];
  }
  printf("%lld\n",ans);
  return 0;
}