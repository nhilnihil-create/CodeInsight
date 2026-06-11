#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,v,p,s,mx,c,r,b,a[100005];
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1),c=a[n-p+1],b=0,r=p,v=n-v,s=0,mx=0;
	for(int i=n;i>=1;i--) if(a[i]<c) break;else b++;
	for(int i=n-p;i>=1;i--)
	{
		s+=(a[i+1]-a[i])*(n-p+1-i);
		if(s<=min(n-p,v)*m&&a[n-p+1]-a[i]<=m) r++;else break;
	}
	return printf("%lld\n",r),0;
}//ZKAKIOI