/*!enjoy karo yaar!*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

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
const ll inf=1e9,M=1e9+7;
const int N=1e5+5;

vi v[N];
int dp[N][3];

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
    }

    int s,t;
    cin>>s>>t;

    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<3;++j)
            dp[i][j]=inf;
    }

    priority_queue<pii> pq;
    dp[s][0]=0;
    pq.push({0,s});

    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();

        int dist=-p.F,x=p.S;
        int a=dist%3,b=(dist+1)%3;
        for(auto c:v[x])
        {
            if(dp[c][b]>dp[x][a]+1)
            {
                dp[c][b]=dp[x][a]+1;
                pq.push({-dp[c][b],c});
            }
        }
    }

    if(dp[t][0]==inf)
        cout<<-1;
    else
        cout<<dp[t][0]/3;
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

