#include<bits/stdc++.h>
#define ll long long 
#define MM(arr,x) memset(arr,x,sizeof(arr))
#define INF 0x3f3f3f3f
#define Maxn 1e5+10;
using namespace std;
int a[200050],n,k;
bool check(int mid)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>mid) ans+=a[i]/mid;
		if(ans>k) return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>k;
	int l=1,r=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		r=max(a[i],r);
	}
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid;
		}
		else l=mid+1;
	}
	cout<<l;
	return 0;
} 
