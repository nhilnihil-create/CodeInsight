/*!enjoy karo yaar!*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

// gist: how the answer for the current index depends on the previous index?
//       (in other words, how to build the DP solution?)


#include<bits/stdc++.h>
using namespace std;

#define     int             long long int
#define     fast()          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)          begin(x),end(x)
#define     rz(x)           resize(x)
#define     asn(x,y)        assign(x,y)
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     sz(x)           ((int)size(x))
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
#define     remax(a,b)      a=max(a,b)
#define     remin(a,b)      a=min(a,b)
#define     bitcount(x)     __builtin_popcountll(x)
#define     iceil(n,x)      (((n)-1)/(x)+1)
#define     dbug(x)         cout<<#x<<": "<<(x)<<"\n"
#define     flush           fflush(stdout)
#define     show(x)         for(auto zz:x)cout<<zz<<" ";cout<<"\n";
#define     show2(x)        for(auto zz:x)cout<<zz.F<<" "<<zz.S<<"\n";

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ld pi=acos(-1);
const ll inf=1e18,M=998244353;
const int N=3e3+5;

int dp[N][N];           // dp[i][j] -> the answer for sum "j" when we have processed the first "i" indices

void solve()
{
    int n,sum;
    cin>>n>>sum;

    vi v(n);
    for(int i=0;i<n;++i)
        cin>>v[i];

    mem(dp,0);
    dp[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=sum;++j)
        {
            dp[i][j]=(2*dp[i-1][j])%M;                 // we have two choices -> to pick this index or not

            if(j-v[i-1]>=0)
                dp[i][j]=(dp[i][j]+dp[i-1][j-v[i-1]])%M;        // we have only one choice -> to pick this index
        }
    }

    cout<<dp[n][sum];
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
