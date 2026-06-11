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
ll power(ll x,ll y){ll res=1; while(y>0){if(y&1) res=res*x;y=y>>1;x=x*x;}return res;} // modular exponent
ll n,m;
const int maxn=1e5+5;
ll a[maxn];
int main()
{
    ios_base::sync_with_stdio(false); // don't use printf and scanf
    cin.tie(NULL); // cout<<fixed<<setprecision
	cin>>n>>m;
	rep(i,n)
	{
		cin>>a[i];
		a[i]/=2;
	}	
	if(n==1)
	{
		ll f=m/a[0];
		if(f%2) cout<<(f/2)+1;
		else cout<<(f/2);
		cout<<'\n';
		return 0;
	}
	ll lc=a[0];
	repA(i,1,n-1)
	{
		lc=(a[i]*lc)/(gcd(a[i],lc));
	}
	int flag=1;
	rep(i,n)
	{
		ll val=lc/a[i];
		if(val%2==0)
		{
			flag=0;
			break;
		}
	}
	if(flag==0)
	{
		cout<<0<<'\n';
	}
	else
	{
		ll f=m/lc;
		if(f%2) cout<<(f/2)+1;
		else cout<<(f/2);
		cout<<'\n';
	}
	return 0;
}
// JUST ASK YOURSELF DID YOU GIVE YOUR BEST ? ISSE ZYADA
// KUCH KAR BHI NAHI SAKTE !! ENJOY AND GIVE YOUR BEST!!

