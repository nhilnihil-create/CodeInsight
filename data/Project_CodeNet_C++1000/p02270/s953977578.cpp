#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <iostream>
#include <set>
typedef long long ll;
using namespace std;
int a[100005],n,k;
int f(ll x)
{
	int j=1;
	for(int i=1;i<=k;i++)
	{
		ll sum=0;
		while(sum+a[j]<=x)
		{
			sum=sum+a[j];
			if(j==n)
			return n;
			j++;
		}
	}
	return j-1;
}
ll ans;
ll solve()
{
	ll mid,left=0,right=1e10;
	int v;
	while(right-left>1)
	{
		mid=(left+right)/2;
		v=f(mid);
		if(v>=n)
		right=mid;
		else left=mid;
	}
	return right;
}
int main()
{
   cin>>n>>k;
   for(int i=1;i<=n;i++)
   {
   	cin>>a[i];
   }
   ans=solve();
  cout<<ans<<"\n";
	return 0;
}

