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
ll h[309];
ll a[309][309];
void solve()
{
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	for(ll i=0;i<=(n+1);i++)
	{
		for(ll j=0;j<=k;j++)
		{
			a[i][j]=inf;
		}
	}
	a[0][0]=0;
	ll ans=inf;
	for(ll i=0;i<=(n+1);i++)
	{
		for(ll j=0;j<=k;j++)
		{
			for(ll l=0;l<=k;l++)
			{
				if((j+l)>k)
					break;
				if((i+l+1)>(n+1))
					break;
				a[i+l+1][j+l]=min(a[i+l+1][j+l],a[i][j]+max((ll)0,h[i+l+1]-h[i]));
			}
			if(i==(n+1))
				ans=min(ans,a[i][j]);
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
