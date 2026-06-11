#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main()
{
	ll n,ans=0;
	cin>>n;
	ans+=n-1;
	for(ll i=2;i<n;i++)
	{
		if(n%i==0)
			ans+=(n/i - 1);
		else
			ans+=(n/i);
	}
	cout<<ans<<endl;


}
