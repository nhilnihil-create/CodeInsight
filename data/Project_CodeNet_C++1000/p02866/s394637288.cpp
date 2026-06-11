#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const ll mod=998244353;
ll a[maxn];
ll poow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans%mod;
}
int main()
{
	ll x,n;
	cin>>n;
	ll ma=0;
	bool flag=0;
	cin>>x;
	if(x!=0) flag=1;
	for(int i=1;i<n;i++)
	{
		cin>>x;
		a[x]++;	
		if(!x) flag=1;
		ma=max(ma,x);
	}
	ll sum=1;
	if(flag) cout<<0<<"\n";
	else{
		for(int i=2;i<=ma;i++)
		{
			sum=(sum*poow(a[i-1],a[i]))%mod;
		}
		cout<<sum<<"\n";
	}
	return 0;
} 