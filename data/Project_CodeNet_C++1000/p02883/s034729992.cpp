#include "bits/stdc++.h"
using namespace std;
const int maxn=2e5+10;
int n;
long long k,a[maxn],f[maxn];
bool check(long long x)
{
	long long sum=0LL;
	for(int i=0;i<n;i++)
	{
		sum+=max(0LL,a[i]-x/f[i]);
	}
	if(sum>k)
	{
		return false;
	}
	return true;
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>f[i];
	}
	//С*�� 
	sort(a,a+n);
	sort(f,f+n);
	reverse(f,f+n);
	long long l=0LL,r=1e12;
	for(int i=0;i<64;i++)
	{
		long long mid=(l+r)/2LL;
//		cout<<mid<<" ##"<<endl;
		if(!check(mid))
		{
			l=mid+1LL;
		}
		else
		{
			r=mid;
		}
	}
	cout<<l<<endl;
	return 0;
}
