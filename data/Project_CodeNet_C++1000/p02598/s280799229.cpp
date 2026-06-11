#include<bits/stdc++.h>
#define fint register int
#define p 374282
#define h 5001
#define int long long
using namespace std;
const int inf=1e9;
int a[p]; 
int n,k;
inline int check(int x);
signed main()
{
	cin>>n>>k;
	int maxxs=0,minns=3478923;
	for(fint i=1;i<=n;i++)
	cin>>a[i],maxxs=max(maxxs,a[i]),minns=min(minns,a[i]);
	int l=1,r=inf;
	int ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		r=mid-1,ans=mid;
		else
		l=mid+1;
	}
	cout<<ans;
	return 0;
}

inline int check(int x)
{
	int tt=0;
	for(fint i=1;i<=n;i++)
	tt+=(a[i]-1)/x;
	if(tt<=k)
	return 1;
	return 0;
}

/*
给你 N个木头，长度分别是ai 

让你切 K次，

切完后，让你求长度最大的木头最小值，（最大值最小)
*/