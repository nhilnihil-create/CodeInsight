#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e18+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=40000;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound
int main()
{
	ll i,j,k,l,d,m,n,x;
	string s;
	cin>>x>>k>>d;
	if(x<0)
		x=-x;
	ll ans=k;
	j=x/d;
	if(k<=j)
	{
		cout<<x-k*d;
	}
	else
	{
		ll ans1;
		ans=x-j*d;
		ans1=ans;
		k=k-j;
		if(k%2==1)
		{
			ans1=ans+d;
		}
		k--;
		l=ans-d;
		if(k%2==1)
		{
			ans1=min(ans1,l+d);
		}
		else
			ans1=min(ans1,abs(l));
		cout<<ans1;
	}

	//cout<<l;
}