#include<bits/stdc++.h>
#define ll long long int
#define pragi(a,b) for(ll i = a;i<b;i++)
#define pragj(a,b) for(ll j = a;j<b;j++)
#define pragk(a,b) for(ll k = a;k>=b;k--)
#define all(v) (v.begin(),v.end())
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define KAKA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long double ld;
typedef pair<int, int> pii;
//typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;

ll negmd(ll a,ll n){
	return (n+(a%n))%n;
}
 
ll modexp(ll x,ll n,ll m)
{
	if(n == 0) return 1;
	else if(n & 1)
	{
		return (x * modexp(x,n - 1,m))%m;
	}
	else
	{
		ll y = modexp(x,n/2,m);
		return (y * y)%m;
	}
	
}
ll flt(ll a,ll p)
{
	return modexp(a,p - 2,p);
}
void Compute(ll n,ll a,ll b)
{
	KAKA
    ll x = 1,y = 1;
	pragi(0,a)
	{
		x = ((x % mod) * ((n - i) % mod))%mod;
	}
	pragi(0,a)
	{
		y = ((y % mod) * ((a - i) % mod))%mod;
	}
	ll yinv = flt(y,mod);
    ll ans1 = (x * yinv)%mod;
	//cout<<ans1<<"\n";
	 x = 1,y = 1;
	pragi(0,b)
	{
		x = ((x % mod) * ((n - i) % mod))%mod;
	}
	pragi(0,b)
	{
		y = ((y % mod) * ((b - i) % mod))%mod;
	}
	yinv = flt(y,mod);
	ll ans2 = (x * yinv)%mod;
	//cout<<ans2<<"\n";
	ll ans3 = modexp(2,n,mod);
    ll ans = (ans3 - ans1 - ans2 - 1);
	if(ans < 0) ans = negmd(ans,mod);
	else ans %= mod;
	cout<<ans<<"\n";
}
int main()
{
	KAKA
	ll n,a,b;
	cin>>n>>a>>b;
	Compute(n,a,b);
}