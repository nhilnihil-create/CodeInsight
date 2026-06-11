#include<bits/stdc++.h>
using namespace std;
typedef		 long long int    ll;
typedef		vector<ll>      vll;
#define     fi              first
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
    ll n,m,k;
    cin>>n>>m>>k;
    vll v1(n+1),v2(m+1);
    for(ll i=1; i<=n; i++)
    {
        cin>>v1[i];
        v1[i]+=v1[i-1];
    }

    for(ll i=1; i<=m; i++)
    {
        cin>>v2[i];
        v2[i]+=v2[i-1];
    }

    ll ans=0;

    for(ll i =0; i<=n; i++)
    {
        if(v1[i]<=k)
        {
            ll z=upper_bound(all(v2),k-v1[i])-v2.begin()-1;
            ans=max(ans,i+z);
        }
    }
    cout<<ans<<nn;



}


/* Final check before submit :

1. array size or integer overflow,like uninitialised 0 index.

2. Think twice,code once.check all possible counter test case.

3. Be careful about corner case! n=1?k=1? something about 0?

4. avoid stupid mistake!complexity(t/m)?precision error?submit same code twice?

5. if got WA than remember that you are missing something common.
   *** Be confident!!! who knows? may be your one step back to AC ***

*/



