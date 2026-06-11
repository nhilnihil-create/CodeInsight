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
ll a[100009],b[64];
ll gmatrix[100009][64];//in case of multiple queries use 2-D array
ll basis[100009];//for multiple queries use array
void add(ll x,ll index)
{
    /*basis[index]=basis[index-1];
    for(ll i=63;i>=0;i--)
    {
        gmatrix[index][i]=gmatrix[index-1][i];
    }*/
    for(ll i=63;i>=0;i--)
    {
    	if(b[i])
    		continue;
        if(x&((ll)1<<i))
        {
            if(gmatrix[index][i])
                x^=gmatrix[index][i];
            else
            {
                gmatrix[index][i]=x;
                basis[index]++;
                return;
            }
        }
    }
}
ll maximum(ll x,ll index)//for finding maximum xor
{
    for(ll i=63;i>=0;i--)
    {
    	if(b[i])
    		continue;
        if(!(x&((ll)1<<i)))
        {
            x^=gmatrix[index][i];
        }
    }
    return x;
}
void solve()
{
	ll n;
	cin>>n;
	ll x;
	ll z=0;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		x=a[i];
		for(ll j=0;j<62;j++)
		{
			ll p=x%2;
			b[j]^=p;
			x/=2;
		}
	}
	for(ll i=0;i<n;i++)
	{
		x=a[i];
		z^=x;
		add(x,0);
	}
	ll p=maximum(0,0);
	z^=p;
	cout<<p+z;
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
