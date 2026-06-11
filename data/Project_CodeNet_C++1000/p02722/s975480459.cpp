#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    scanf("%lld", &n);
    ll res= 0;
    for(ll i=1; i*i<=n; i++)
    if(!(n%i))
    {
        if(i!=1)
        {
            ll x= i;
            ll m= n;
            while(!(m%x))m/= x;
            if(m%x==1ll)res++;
        }
        ll x= n/i;
        if(x!=i)
        {
            ll m= n;
            while(!(m%x))m/= x;
            if(m%x==1ll)res++;
        }
    }
    n--;
    for(ll i=1; i*i<=n; i++)
    if(!(n%i))
    {
        if(i!=1)res++;
        if((n/i)!=i)res++;
    }
    printf("%lld\n", res);
    return 0;
}
