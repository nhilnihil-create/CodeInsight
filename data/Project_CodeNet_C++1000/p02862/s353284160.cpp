#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;
 
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
 
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;
 
#define _  %  MOD
#define __ %= MOD
 
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      fill(a)           memset(a, 0, sizeof (a))
 
#define      swap(a,b)        {a=a+b;b=a-b;a=a-b;}
#define      rep(i, n)         for(ll i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(ll i = a; i <= (n); ++i)
#define      repD(i, a, n)     for(ll i = a; i >= (n); --i)
#define watch(x) cout << (#x) << " is " << (x) <<endl
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
#define fbo find_by_order
#define ook order_of_key
 
ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}
ll power(ll x,ll y){ll res=1; while(y>0){if(y&1) res=(res*x)%INF;y=y>>1;x=(x*x)%INF;}return res%INF;} // modular exponent
const int maxn=1e6+1;
ll inv(ll x)
{
	return power(x,INF-2);
}
ll fact[maxn],invfact[maxn];
void work()
{
	fact[0]=1;
	invfact[0]=1;
	for(ll i=1;i<maxn;i++)
	{
		fact[i]=(i*fact[i-1])%INF;
		invfact[i]=inv(fact[i]);
	}
}
ll C(ll n,ll r)
{
	if(r>n) return 0;
	ll ans=1ll;
	ans=fact[n];
	ans*=invfact[r];
	ans%=INF;
	ans*=invfact[n-r];
	ans%=INF;
	return ans;
}
int main()
{
    ios_base::sync_with_stdio(false); // don't use printf and scanf
    cin.tie(NULL); // cout<<fixed<<setprecision
	ll x,y;
	cin>>x>>y;
	if((x+y)%3==0 && 2*x>=y && 2*y>=x)
	{
		work();
		ll i=2*x-y;
		i/=3;
		ll j=2*y-x;
		j/=3;
		ll ans=C(i+j,i);
		cout<<ans<<'\n';
	}
	else cout<<0<<'\n';
	return 0;
}
// JUST ASK YOURSELF DID YOU GIVE YOUR BEST ? ISSE ZYADA
// KUCH KAR BHI NAHI SAKTE !! ENJOY AND GIVE YOUR BEST!!

