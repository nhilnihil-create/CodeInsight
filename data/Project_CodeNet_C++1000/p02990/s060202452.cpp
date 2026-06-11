#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define frw(i, a, b) for(int i = a; i < b; i++)
#define fi first
#define se second
#define pb push_back
#define in insert
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) int(a.size())
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define vpii vector<pii>
#define vpiii vector<piii>
#define vpll vector<pll>
#define vplll vector<plll>
#define mod 1000000007


int po(ll x,ll y)
{
	//ll y=mod-2;
	unsigned int res=1;
	while(y>0)
	{
		if(y&1)
			res=(res*x)%mod;
		y=y>>1;
		x=(x*x)%mod;
	}
	return res;
}
ll md(ll a){
  ll res = a%mod;
  if(res<0)res=res + mod;
  return res;
}
int main() {
	ll n,b;
	ll r;
	cin>>n>>b;
	r=n-b;
	ll f[2001],fi[2001];
	f[0]=1;
	fi[0]=1;
	for(int i=1;i<2001;i++)
	{
		f[i]=(f[i-1]*i)%mod;
		fi[i]=po(f[i],mod-2);

	}
	ll ans;
	for(int i=1;i<=b;i++)
	{
		if(r+1<i)
		{
			cout<<"0"<<endl;

		}
		else
		{
			ll ans=0;
			ans=md(fi[b-i]*md(fi[i-1]*md(f[b-1]*md(f[r+1]*md(fi[i]*fi[r+1-i])))));
			
			cout<<ans<<endl;
		}
	}


	
}
