#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ps push
#define pll pair<long,long>
#define INF 10000000000000000
typedef long long ll;
#define PI 3.14159265

vector<ll> v;
ll n,k;

bool chk(ll s)
{
	vector<ll> v1;
	ll s1=0;
	for(ll i=0;i<n;i++)
	{
		v1.pb(v[i]%s);
		s1+=s-(v1[i]);
	}
	sort(v1.begin(),v1.end());
	ll s2=0;
	for(ll i=0;i<n;i++)
	{
		s1-=(s-v1[i]);
		s2+=v1[i];
		if(s2==s1 && s2<=k)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
	//ll n;
	cin>>n;
	cin>>k;
	ll s=0;
	v.resize(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
		s+=v[i];
	}
	
	ll ans=0;
	for(ll i=1;i*i<=s;i++)
	{
		if(s%i==0)
		{
			if(chk(i))
				ans=max(ans,i);
			if(chk(s/i))
				ans=max(ans,s/i);
		}
	}
	cout<<ans;
	
}				
					
					
