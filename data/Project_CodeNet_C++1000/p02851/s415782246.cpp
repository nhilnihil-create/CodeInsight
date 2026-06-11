#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265358979
#define EPS 1e-8
#define mod 1000000007
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl "\n"
	 
const ll INF=(ll)2e18;
		
		
		
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
				
	ll n,k;
	cin>>n>>k;
	
	vector<ll> v(n+1);
	
	for(ll i=1;i<=n;i++)
	{
		cin>>v[i];
		v[i]--;
	}
	vector<ll> pref(n+1,0);
	
	for(ll i=1;i<=n;i++)
	{
		pref[i]=pref[i-1];
		pref[i]+=v[i];
		pref[i]%=k;
		
	}
	
	map<ll,ll> rem;
	ll ans=0;
	for(ll i=0;i<min(k,n+1);i++)
	{
		ans+=rem[pref[i]];
		rem[pref[i]]++;
	}
	
	for(ll i=k;i<=n;i++)
	{
		rem[pref[i-k]]--;
		ans+=rem[pref[i]];
		rem[pref[i]]++;
	}
	cout<<ans;
}
