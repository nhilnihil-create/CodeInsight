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
const ll inf=1e18,M=1e9+7;
const int N=1e5+5;

int dp[N][2];

string s;

int rec(int ind,int tight)
{
    if(ind==-1)
        return 1;

    int& res=dp[ind][tight];
    if(res!=-1)
        return res;

    res=0;
    int nt;
    for(int i=0;i<3;++i)
    {
        if(i)
        {
            if(s[ind]=='0')
            {
                if(tight)
                    break;
                else
                    nt=0;
            }
            else
                nt=tight;
        }
        else
        {
            if(s[ind]=='0')
                nt=tight;
            else
                nt=0;
        }

        res=(res+rec(ind-1,nt))%M;
    }

    //cout<<ind<<" "<<tight<<" "<<res<<"\n";

    return res;
}

void solve()
{
    mem(dp,-1);

    cin>>s;

    reverse(all(s));

    int ans=rec(sz(s)-1,1);
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

