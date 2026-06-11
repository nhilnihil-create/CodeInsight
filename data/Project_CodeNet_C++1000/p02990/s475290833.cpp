#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e9+7)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
ll gcd(ll a,ll b){if(!b)return a;else return gcd(b,a%b);}
vector<ll> fact;
vector<ll> ifact;
ll add(ll a,ll b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
ll mult(ll a,ll b)
{
	return (a*1LL*b)%MOD;
}
ll binpow(ll a, ll b)
{
	ll r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
ll choose(ll a, ll b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	ll r = mult(ifact[b],ifact[a-b]);
	r = mult(r,fact[a]);
	return r;
}
ll inv(int a){return binpow(a,MOD-2);}
void init(ll n)
{
	fact.clear(); ifact.clear();
	fact.resize(n+1);
	ifact.resize(n+1);
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=n;i++){fact[i]=mult(fact[i-1],i);}
	ifact[n] = inv(fact[n]);
	for(int i=n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
}
ll rchoose(ll n,ll r){
	ll res = 1;
	for(int i=0;i<r;i++)res = mult(res,n-i);
	return res;
}
int main()
{
	ll n,k;
	cin>>n>>k;
	init(n);
	ll red = n-k;
	for(ll i=1;i<=k;i++){
		cout<<mult(choose(red+1,i),choose(k-1,i-1))<<'\n';
	}
}
