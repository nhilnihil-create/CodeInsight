#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int n,t1,t2,cnt[N];bool fl;char a[N];
int main()
{
	scanf("%d %s",&n,a);
	if(n==2) {printf("%d\n",abs(a[0]-a[1]));return 0;}
	for(int i=1;i<=n;++i) if(!(i%2)) cnt[i]=cnt[i/2]+1;
	for(int i=1;i<=n;++i) cnt[i]+=cnt[i-1];
	for(int i=0,x,t;i<n-1;++i)
	{
		x=abs(a[i]-a[i+1]);
		if(cnt[i]<cnt[n-2]-cnt[n-2-i]) t=0;else t=1;
		if(x==1) t1=(t1+t)%2,fl=1;if(x==2) t2=(t2+t)%2; 
	}if(t1) puts("1");else if(fl || (!fl && !t2)) puts("0");else puts("2");
	return 0;
}