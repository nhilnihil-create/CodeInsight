#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e5+5;
int n,m,v,p,a[MAXN];
bool check(int pos)
{
	int dev=n-v,k=n-p;
	ll desum=0;
	for(int i=n;i>=1&&k;i--)
	{
		if (i==pos)
			continue;
		if (a[i]-a[pos]>m)
			return false;
		desum+=1LL*max(0,a[i]-a[pos]);
		--k;
	}
	return desum<=1LL*m*dev;
}
int main()
{
	cin>>n>>m>>v>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if (check(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}