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
#define mod 1000000007
#define inf 1000000000000000007
#define eps 0.0000000001
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
ll e[100009],c[100009];
ll power(ll x,ll y)
{
    ll res=1;
  
    while(y>0)
    {
        if(y&1)
            res=res*x;
        res%=mod;
        y=y>>1;
        x=x*x;
        x%=mod;
    } 
    return res; 
}
ll inv(ll x)
{
    return power(x,mod-2);
}
void solve()
{
	ll n,k;
	cin>>n>>k;
	e[1]=1;
	vll v;
	for(ll i=2;i<=k;i++)
	{
		if(c[i]==0)
		{
			v.pb(i);
			e[i]=i-1;
		}
		for(auto j:v)
		{
			if((i*j)>k)
				break;
			c[i*j]=1;
			if(i%j==0)
			{
				e[i*j]=e[i]*j;
				break;
			}
			e[i*j]=e[i]*e[j];
		}
	}
	ll ans=0;
	for(ll i=1;i<=k;i++)
	{
		ll x=e[i];
		ll y=k/i;
		y=power(y,n);
		x*=y;
		x%=mod;
		ans+=x;
		ans%=mod;
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
        //cout<<"Case #"<<i+1<<":"<<endl;
        solve();
    }
    time_taken_end
}