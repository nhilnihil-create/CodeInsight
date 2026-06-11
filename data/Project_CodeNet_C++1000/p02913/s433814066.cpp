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
const int N=1;

vi Hash;

int n;
string s;

int pw(int x,int n,int mod=M)
{
    int res=1;

    x%=mod;
    for(;n;n/=2)
    {
        if(n%2)
            res=(res*x)%mod;

        x=(x*x)%mod;
    }

    return res;
}

int mul(int a,int b,int mod)
{
    int res=(a*b)%mod;
    return res;
}

int prm=131, mod=1000000007;
vector<int> pows,invpows;

void pow_init(int n)
{
    pows.rz(n);
    pows[0]=1;
    for(int i=1;i<n;++i)
        pows[i]=(pows[i-1]*prm)%mod;

    invpows.rz(n);
    invpows[n-1]=pw(pows[n-1],mod-2);
    for(int i=n-2;i>=0;--i)
        invpows[i]=(invpows[i+1]*prm)%mod;
}

void hashit(string str)
{
    int len=str.length();
    int hsh=0;

    Hash.rz(n);
    for(int i=0;i<len;++i)
    {
        hsh=(hsh+mul(str[i]-'a'+1,pows[i],mod))%mod;
        Hash[i]=hsh;
    }
}

int get_hash(int l, int r)
{
    int tmp=0;
    if(l)
        tmp=Hash[l-1];

    int res=(Hash[r]-tmp+mod)%mod;
    res=(res*invpows[l])%mod;

    return res;
}

bool chk(int len)
{
    vector<pii> v;
    for(int i=0;i+len-1<n;++i)
        v.pb({get_hash(i,i+len-1),i});

    sort(all(v));

    for(int i=0;i+len-1<n;++i)
    {
        int j;
        for(j=i+1;j<n && v[j].F==v[i].F;++j);
        --j;

        if(v[i].S+len<=v[j].S)
            return 1;

        i=j;
    }

    return 0;
}

void solve()
{
    cin>>n>>s;

    pow_init(n);
    hashit(s);

    int beg=1,en=n/2;
    int mid,ans=0;
    while(beg<=en)
    {
        mid=(beg+en)/2;

        if(chk(mid))
        {
            ans=mid;
            beg=mid+1;
        }
        else
            en=mid-1;
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

