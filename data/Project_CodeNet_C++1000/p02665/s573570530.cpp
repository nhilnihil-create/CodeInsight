#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include <bits/stdc++.h>
typedef long long ll;
#define N 100010
using namespace std;
int a[N];
ll solve()
{
	ll n;
	ll add=0;
	cin>>n;
	ll ans=1;
	for (ll i=0;i<=n;i++) 
	{
		cin>>a[i];
	}
	ll now=1;
	if (n==0)
	{
		if (a[0]==1)
			return 1;
		else
			return -1;
	}
   else
   {
        if(a[0]!=0)
            return -1;
   }
	for (ll i=1;i<=n;i++) 
	{
		add+=a[i];
	}
   for (ll i=1;i<=n;i++)
	{
		now=min(ll(now<<1),add);
		ans+=now; 
		now-=a[i];
		add-=a[i];
		if (now<0)
			return -1;
	}
	if (now!=0)
		return -1;
	return ans;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	int t;
//	cin>>t;
//	while (t--) 
		cout<<solve()<<endl;
	return 0;
}