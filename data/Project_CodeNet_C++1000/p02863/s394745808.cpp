/*!enjoy karo yaar!*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

//#define     int             long long int
#define     fast()          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)          begin(x),end(x)
#define     rz(x)           resize(x)
#define     asn(x,y)        assign(x,y)
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     sz(x)           ((int)(x.size()))
#define     eb              emplace_back
#define     pb              push_back
#define     pf              push_front
#define     pob             pop_back
#define     pof             pop_front
#define     ins             insert
#define     vi              vector<int>
#define     pii             pair<int,int>
#define     mii             map<int,int>
#define     F               first
#define     S               second
#define     makep           make_pair
#define     maket           make_tuple
#define     remax(a,b)      a=max(a,b)
#define     remin(a,b)      a=min(a,b)
#define     bitcount(x)     __builtin_popcountll(x)
#define     iceil(n,x)      (((n)+(x)-1)/(x))
#define     gcd(a,b)        (__gcd((a),(b)))
#define     lcm(a,b)        ((a)*((b)/gcd((a),(b))))
#define     dbug(x)         cout<<#x<<": "<<(x)<<"\n"
#define     flush           fflush(stdout)
#define     show(x)         for(auto zz:x)cout<<zz<<" ";cout<<"\n";
#define     show2(x)        for(auto zz:x)cout<<zz.F<<" "<<zz.S<<"\n";

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ld pi=acos(-1);
const ll inf=1e18,M=1e9+7;
const int N=3e3+5;

// dp[i][j] -> max. value considering i items having at most j weight
int dp[N][N];

void solve()
{
    mem(dp,0);

    int n,t;
    cin>>n>>t;

    vector<pii> v(n+1);
    for(int i=1;i<=n;++i)
        cin>>v[i].F>>v[i].S;

    sort(all(v));

    int ans=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<t;++j)
            ans=max(ans,dp[i-1][j]+v[i].S);

        for(int j=0;j<t;++j)
        {
            if(j-v[i].F>=0)
                remax(dp[i][j],dp[i-1][j-v[i].F]+v[i].S);

            remax(dp[i][j],dp[i-1][j]);
            if(j) remax(dp[i][j],dp[i][j-1]);
        }
    }

    cout<<ans;
}

int32_t main()
{
    fast();

    int t=1;
    //cin>>t;
    for(int z=1;z<=t;++z)
    {
        solve();
        //cout<<"\n";
    }

    return 0;
}

