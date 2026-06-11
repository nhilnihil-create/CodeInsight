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
	cin>>n>>k>>c;
	string s;cin>>s;vtr<ll> a,b;ll i;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='o')
		{
			a.pb(i+1);
			i+=c;
			if(a.size()>=k)break;
		}
	}
	for(i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='o')
		{
			b.pb(i+1);
			i-=c;
			if(b.size()>=k)break;
		}
	}reverse(b.begin(),b.end());vtr<ll> ans;
	for(i=0;i<k;i++)
	{
		if(a[i]==b[i])ans.pb(a[i]);
	}
	for(i=0;i<ans.size();i++)cout<<ans[i]<<endl;
	}
}