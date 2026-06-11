
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt" , "r" , stdin);
	// freopen("output.txt" , "w" , stdout);
	// #endif

	ll n,k,m=1e9+7,ans=0,k1,k2;
	cin>>n>>k;
	k1=((k*(k+1))/2)%m;
	k2=((k*(k-1))/2)%m;
	ll a[n+1];
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	ll b[n+1]={0},c[n+1]={0};
	b[1]=0;
	for(ll i=2;i<=n;i++)
	{
		for(ll j=1;j<i;j++)
		{
			if(a[j]>a[i])
				b[i]++;
			else if(a[j]<a[i])
				c[i]++;
		}
		ans=(ans+b[i]*k1)%m;
		ans=(ans+c[i]*k2)%m;

	}
	cout<<ans<<endl;

	
	
}
