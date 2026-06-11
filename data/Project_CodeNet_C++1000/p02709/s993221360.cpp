#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(),v.end()
#define repf(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define MOD 998244353 

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ordered_set<ll> dp;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll power(ll a, ll n, ll m)
{
    ll ans=1;
    while(n)
    {
        if(n&1) ans=(ans*a)%m;
        n>>=1;
        a=(a*a)%m;
    }
    return ans;
}

ll invmod(ll a, ll m)
{
    return power(a,m-2,m);
}

bool dp[2001][2001];
string ss[10]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
    
void solve()
{
    ll n;
    cin>>n;
    pair<ll,ll> p[n+1];
    repf(i,1,n+1) 
    {
        cin>>p[i].fi;
        p[i].se=i;
    }
    sort(p+1,p+n+1);
    reverse(p+1,p+n+1);
    ll dp[n+1][n+1];
    memset(dp,0,sizeof dp);
    repf(i,1,n+1)
    {
        repf(j,0,i)
        {
            ll L=j;
            ll R=i-1-j;
            dp[L+1][R]=max(dp[L+1][R],dp[L][R]+abs(L+1-p[i].se)*p[i].fi);
            R=j;
            L=i-1-j;
            dp[L][R+1]=max(dp[L][R+1],dp[L][R]+abs(n-R-p[i].se)*p[i].fi);
        }
    }
    ll ans=0;
    repf(i,0,n+1) ans=max(ans,dp[i][n-i]);
    cout<<ans<<endl;
}

int main()
{
    IOS;
    ll t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}     