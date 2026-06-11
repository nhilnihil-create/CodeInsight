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
void solve()
{
    ll n,x,y;
    cin>>n;
    ll m1,m2,m3,m4;
    cin>>x>>y;
    m1=m2=x-y;m3=m4=x+y;
    ll ans=0;
    for(ll j=1;j<n;j++)
    {
    	cin>>x>>y;
    	ll a1=x-y;
    	ll a2=x+y;
    	ans=max(ans,abs(a1-m1));
    	ans=max(ans,abs(a1-m2));
    	ans=max(ans,abs(a2-m3));
    	ans=max(ans,abs(a2-m4));
    	m1=max(m1,a1);
    	m2=min(m2,a1);
    	m3=max(m3,a2);
    	m4=min(m4,a2);
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