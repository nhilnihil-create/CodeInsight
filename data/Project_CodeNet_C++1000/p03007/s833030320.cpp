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
const int N=1;

void solve()
{
    int n;
    cin>>n;

    vi pos,neg;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;

        if(x<=0)
            neg.pb(x);
        else
            pos.pb(x);
    }

    sort(all(neg));
    sort(all(pos));

    int ans=abs(accumulate(all(neg),0))+accumulate(all(pos),0);
    if(!sz(neg))
    {
        ans-=2*pos[0];
        cout<<ans<<"\n";

        int cur=pos[0];
        for(int i=1;i<sz(pos)-1;++i)
        {
            cout<<cur<<" "<<pos[i]<<"\n";
            cur-=pos[i];
        }

        cout<<pos.back()<<" "<<cur<<"\n";
        return;
    }

    if(!sz(pos))
    {
        ans+=2*neg.back();
        cout<<ans<<"\n";

        int cur=neg.back();
        for(int i=n-2;i>=0;--i)
        {
            cout<<cur<<" "<<neg[i]<<"\n";
            cur-=neg[i];
        }

        return;
    }

    cout<<ans<<"\n";

    int a=neg[0];
    for(int i=1;i<sz(pos);++i)
    {
        cout<<a<<" "<<pos[i]<<"\n";
        a-=pos[i];
    }

    int b=pos[0];
    for(int i=1;i<sz(neg);++i)
    {
        cout<<b<<" "<<neg[i]<<"\n";
        b-=neg[i];
    }

    cout<<b<<" "<<a<<"\n";
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

