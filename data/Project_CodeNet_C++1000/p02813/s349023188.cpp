#include<bits/stdc++.h>
using namespace std;
typedef		 long long int    ll;
typedef		 long double   ld;
typedef		vector<ll>      vll;
#define     fi              first
#define     print(v)        for(ll i:v) cout<<i<<ss
#define     se              second
#define		pb              push_back
#define		nn              "\n"
#define		all(p)          p.begin(),p.end()
#define		zz(v)           (ll)v.size()
#define 	S(a)            scanf("%lld",&a)
#define 	SS(a,b)         scanf("%lld %lld",&a,&b)
#define 	SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define		ss              ' '
#define     pii             pair<ll,ll>
#define		gcd(a,b)        __gcd(a,b)
#define		lcm(a,b)        (a*b)/gcd(a,b)
const double eps = 1e-8;

ll a[100];
ll b[100];

ll n;
vll v;
ll vis[100];
ll cnt=0;
ll cnt1=0;
ll cnt2=0;
void go()
{
    if(zz(v)==n)
    {
        cnt++;
        ll f=1;
        for(ll j=0; j<zz(v); j++)
        {
            if(a[j]!=v[j])
                f=0;
        }
        if(f)
            cnt1=cnt;

        f=1;

        for(ll j=0; j<zz(v); j++)
        {
            if(b[j]!=v[j])
                f=0;
        }
        if(f)
            cnt2=cnt;

    }
    for(ll i=1; i<=n; i++)
    {
        if(vis[i])
            continue;

        v.pb(i);
        vis[i]=1;
        go();
        v.pop_back();
        vis[i]=0;
    }
}

int main()
{

//    ios::sync_with_stdio(0);
//    cin.tie(0);

    ll ans=0;
    // ll n;
    cin>>n;

    ll f=1;
    for(ll i=1; i<n; i++)
        f*=i;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }




    for(ll i=0; i<n; i++)
    {
        cin>>b[i];
    }
    go();

    cout<<abs(cnt2-cnt1)<<nn;






}


/* Final check before submit :

1. array size or integer overflow,like uninitialised 0 index.

2. Think twice,code once.check all possible counter test case.

3. Be careful about corner case! n=1?k=1? something about 0?

4. avoid stupid mistake!complexity(t/m)?precision error?submit same code twice?

5. if got WA than remember that you are missing something common.
   *** Be confident!!! who knows? may be your one step back to AC ***
4. minus mod ans=(ans-k+mod)%mod;

*/




