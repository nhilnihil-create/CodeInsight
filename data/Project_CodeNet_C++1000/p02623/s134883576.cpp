#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	vector<ll> a(n);vector<ll> b(m);
	vector<ll> prefa(n+2);vector<ll> prefb(m+2);
	prefa[0]=0;prefb[0]=0;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		prefa[i+1]=prefa[i]+a[i];
	}
	for(ll i=0;i<m;i++)
	{
		cin>>b[i];
		prefb[i+1]=prefb[i]+b[i];
	}
	ll ans=0;ll j=m;
	for(ll i=0;i<n+1;i++)
	{
		if(prefa[i]>k){
			break;
		}
		ll target=(k-prefa[i]);
		ll lo=0;ll hi=m;
		while(lo<=hi)
		{
			ll mid=lo+(hi-lo)/2;
			if(prefb[mid]<=target)
			{
				j=mid;
				lo=mid+1;
			}
			else{
				hi=mid-1;
			}
			
		}
	
		ans=max(ans,i+j);
		
	}
	cout<<ans<<"\n";
	
	return 0;
}