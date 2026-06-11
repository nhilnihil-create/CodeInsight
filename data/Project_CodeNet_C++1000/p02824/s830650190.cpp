#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,v,p,a[100001],ans,a1;
bool cmp(int i,int j){return i>j;}
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
	ans=p;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=p+1;i<=n;i++)
	{
		if(a[i]+m<a[p])break;
		if(v<=p+n-i)++ans;
		else if(((v-p-n+i)*m-a1-1)/(i-p)+1+a[p]<=a[i]+m)++ans;
		a1+=a[p]-a[i];
	}
	printf("%lld",ans);
	return 0;
 } 
