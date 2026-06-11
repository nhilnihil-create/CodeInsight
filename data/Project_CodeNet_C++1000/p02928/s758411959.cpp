#include <bits/stdc++.h>
#include<limits.h>
#include<stdio.h>
#include<cstring>
#include<string>
using namespace  std;
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define fi first
#define se second
#define rsz(a,n) a.resize(n)
#define test(t) ll t;cin>>t;while(t--)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define fillv(a,k) memset(a,k,sizeof(a))
#define leadzero(a) __builtin_clz(a) //count leading zeros
#define trailzero(a) __builtin_ctz(a) //count trailing zeros
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
#define ln cout<<"\n"
// #define sp cout<<" "
#define spaceprint(a,i,s,n) {forsn(i,s,n) { cout<<a[i]; sp;}}
#define lineprint(a,i,s,n) {forsn(i,s,n) {cout<<a[i]; ln;}}
#define maxe(a) *max_element(a.begin(),a.end())
#define maxi(a) max_element(a.begin(),a.end())-a.begin()
#define mine(a) *min_element(a.begin(),a.end())
#define mini(a) min_element(a.begin(),a.end())-a.begin()
#define all(c) c.begin(),c.end()
#define trav(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element)  (find(all(container),element) != container.end())// check the presence of element
//copy(from_begin, from_end, to_begin); copy function
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<string> vs;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
typedef map<ll,ll> m64;
const int LIM = 1e5+5, MOD =  1e9;
#define sumv(v) accumulate(all(v),ll(0))
#define productv(v) accumulate(all(v), ll(1), multiplies< ll >())
ll gcd(ll a, ll b) { if(b == 0) return a; return gcd(b, a % b); }
ll mod=1e9+7;
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }

ll fact[200004];
void compfact ()
{
	fact[0]=1;
	for (ll i=1;i<=200002;i++)
		fact[i]=(fact[i-1]%mod*i%mod)%mod;
}
vp64 v;
ll dp[2002][2002];

void solve (ll ind,ll l , ll r)
{
	if (dp[l][r]!=-1)
		return;
	else if (l>r)
		return;
	else if (l==r)
	{
		dp[l][r]=v[ind].fi*abs(v[ind].se-l);
	}
	else
	{
		solve(ind+1,l+1,r);
		solve(ind+1,l,r-1);
		dp[l][r]=max(dp[l][r],dp[l+1][r]+v[ind].fi*abs(v[ind].se-l));
		dp[l][r]=max(dp[l][r],dp[l][r-1]+v[ind].fi*abs(v[ind].se-r));

	}

}
int main()
{
	fast;
	ll n,k;
	cin>>n>>k;
	ll a[n];
	for (ll i=0;i<n;i++)
		cin>>a[i];
	ll ans=0;
	for (ll i=0;i<n;i++)
	{
		for (ll j=i+1;j<n;j++)
		{
			if (a[i]>a[j])
				ans++;
		}
	}
	ans=((k)%mod*ans%mod)%mod;
	ll f[n];
	memset(f,0,sizeof(f));
	for (ll i=0;i<n;i++)
	{
		for (ll j=0;j<n;j++)
		{
			if (a[i]>a[j])
				f[i]++;
		}
	}
	for (ll i=0;i<n;i++)
	{
		ll temp=(((k-1)*k)/2)%mod;
		ans=(ans+(f[i]%mod*temp%mod)%mod)%mod;
	}
	cout<<ans%mod;

}