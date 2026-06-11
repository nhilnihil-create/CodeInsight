#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x;
int b[300005],sum[300005];
bool judge(int k,int x)
{
	int l=1,r=n,p;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(b[mid]<x&&(mid==n||b[mid+1]>=x))
		{
			p=mid;
			break;
		}
		if(b[mid]<x)l=mid+1;
		else r=mid-1;
	}
	if((n-p)*x+sum[p]>=k*x)return 1;
	return 0;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		b[x]++;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+b[i];
	x=n;
	for(int k=1;k<=n;k++)
	{
		while(x&&!judge(k,x))x--;
		cout<<x<<endl;
	}
}