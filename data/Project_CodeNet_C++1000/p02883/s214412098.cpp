#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define time_taken_start int begtime = clock();
#define time_taken_end int endtime = clock(); \
cerr << "\n\n" << "Time elapsed: " << \
(endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n"; \
return 0;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 998244353
#define inf 100000000000000007
#define eps 0.000000000001
#define pi acosl(-1)
#define pdd pair<ld,ld>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vpl vector<pll>
#define vll vector<ll>
#define mseti multiset <ll>
#define msetd multiset <ll,greater<ll>>
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound 
#define stp fixed<<setprecision(20)
#define endl '\n'
ll a[200009],f[200009];
ll h[200009];
ll n;
void fill(ll x)
{
	for(ll i=0;i<n;i++)
	{
		h[i]=x/f[i];
	}
}
ll check()
{
	ll res=0;
	for(ll i=0;i<n;i++)
	{
		res+=max((ll)0,a[i]-h[i]);
	}
	return res;
}
void solve()
{
	ll k;
	cin>>n>>k;;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(ll i=0;i<n;i++)
	{
		cin>>f[i];
	}
	sort(a,a+n);
	sort(f,f+n,greater<ll>());
	ll l=0,u=1e18,mid;
	ll ans=inf;
	while(l<=u)
	{
		mid=(l+u)/2;
		fill(mid);
		ll z=check();
		if(z>k)
		{
			l=mid+1;
		}
		else
		{
			ans=mid;
			u=mid-1;
		}
	}
	cout<<ans;
}
int main()
{
    FAST
    #ifdef ayk_16
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    #endif
    time_taken_start
    ll t=1;
    //cin>>t;
    for(ll i=0;i<t;i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    time_taken_end
}
