#include <bits/stdc++.h>
#define int long long
using namespace std;
int num[100007],chance=0,n,m,v,p;
bool cmp(int a,int b)
{
	return a>b;
}
signed main() 
{
	scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
	int ans=p;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	}
	sort(num+1,num+1+n,cmp);
	for(int i=1;i<=n-p;i++)
	{
		if(num[p]>num[p+i]+m)
		{
			cout<<ans<<endl;
			return 0;
		}
		int t=v+i-n;
		if(t<=0)
		{
			ans++;
		}
		else 
		if( (t*m-chance-1)/i +num[p]<num[p+i]+m)
		{
			ans++;
		}
		chance+=num[p]-num[p+i];
//		cout<<ans<<' ';
	}
	cout<<ans<<endl;
	return 0;
}
