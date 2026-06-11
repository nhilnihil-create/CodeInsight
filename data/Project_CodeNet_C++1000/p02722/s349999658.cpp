#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
#define pb push_back
#define ins insert
#define pll pair<ll,ll>
#define fi first
#define se second
#define mpr make_pair
#define vtr vector
#define itor iterator 
#define N ll(1e9+7)
#define endl '\n'
#define inf ll(1e9)
using namespace std;
//ll power(ll a,ll b,ll mod)
//{
//	if(b==0)return 1;
//	ll ans=1;
//	while(b>0)
//	{
//		if(b&1)ans=(ans*a)%mod;
//		a=(a*a)%mod;
//		b>>=1;
//	}
//	return ans;
//}
int main()
{
	ios;
	ll t=1;
	while(t--){
		ll n,k,c;
	cin>>n;
	ll ans=2,i,div1,div2;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			div1=i;
			div2=n/i;
			if(div1==div2)
			{
				ans++;
			}
			else
			{
				ll tp=n;
				while(tp%div1==0)
				{
					tp/=div1;
				}
				if(tp%div1==1)
				{
					ans++;
				}
//				tp=n;
//				while(tp%div2==0)
//				{
//					tp/=div2;
//				}
//				if(tp%div2==1)ans++;
			}
		}
	}
	for(i=2;i*i<=(n-1);i++)
	{
		if((n-1)%i==0)
		{
			div1=i;
			div2=(n-1)/i;
			if(div1==div2)
			{
				ans++;
			}
			else
			{
				ans+=2;
			}
		}
	}
	if(n-1==1)ans--;
	cout<<ans;
	}
}