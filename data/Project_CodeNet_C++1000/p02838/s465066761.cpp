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
const int maxn=3e5+5;
ll track[maxn][65];
ll n;
ll a[maxn];
ll f(ll bit,ll x,ll y)
{
	return track[y][bit]-track[x-1][bit];
}
int main()
{
    ios_base::sync_with_stdio(false); // don't use printf and scanf
    cin.tie(NULL); // cout<<fixed<<setprecision
    cin>>n;
	repA(i,1,n)
	{
		cin>>a[i];
		ll idx=0;
		ll val=a[i];
		while(val)
		{
			track[i][idx++]=val%2;
			val/=2;
		}
	}
	repA(i,1,n)
	{
		rep(j,61)
		{
			track[i][j]+=track[i-1][j];
		}
	}
	ll ans=0;
	repA(i,1,n-1)
	{
		rep(j,61)
		{
			if(f(j,i,i)==0)
			{
				ll num=f(j,i+1,n);
				ans+=(num*power(2,j))%INF;
				ans%=INF;
			}
			else
			{
				ll num=f(j,i+1,n);
				num=(n-i)-num;
				ans+=(num*power(2,j))%INF;
				ans%=INF;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
// JUST ASK YOURSELF DID YOU GIVE YOUR BEST ? ISSE ZYADA
// KUCH KAR BHI NAHI SAKTE !! ENJOY AND GIVE YOUR BEST!!

