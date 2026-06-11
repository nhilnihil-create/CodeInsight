#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,ans=0;
void check(ll a)
{
	ll x=n;
	while(x%a==0) x/=a;
	if(x%a==1) ans++;
}
int main()
{
	cin>>n;
	for(ll i=1;i*i<=n-1;i++)
	{
		if((n-1)%i==0)
		{
			if(i>1) ans++;
			if((n-1)/i!=i) ans++;
		}
	}
	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(i>1) check(i);
			if(i!=n/i) check(n/i);
		}
	}
	cout<<ans<<endl;
}