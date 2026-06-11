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


int main()
{
    ll n,m;
    cin>>n>>m;
    ll a1=0,a2=0;
    map<ll,ll>mp1;
    map<ll,ll>mp2;
    for(ll i=0; i<m; i++)
    {
        ll p;
        string s;
        cin>>p>>s;
        if(s=="AC")
        {
            if(mp1[p]==0)
            {
                a1++;
                a2+=mp2[p];
                mp1[p]=1;
            }
            // mp2[p]=1;
        }
        else
        {
            if(mp1[p]==0)
            {
                mp2[p]++;
            }
        }


    }

    cout<<a1<<ss<<a2<<nn;





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




