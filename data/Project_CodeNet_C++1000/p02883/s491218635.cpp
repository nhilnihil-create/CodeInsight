#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ara[200005], b[200005];
bool chck(int n, ll k, ll r)
{
    for(int i=0; i<n; i++)
    if((ara[i]*b[i])>r)
    {
        ll x= r/b[i];
        k-= (ara[i]-x);
        if(k<0)return 0;
    }
    return 1;
}
int main()
{
    ll n, k, sum= 0;
    scanf("%lld %lld", &n, &k);
    for(int i=0; i<n; i++)scanf("%lld", &ara[i]);
    for(int i=0; i<n; i++)scanf("%lld", &b[i]);
    sort(ara, ara+n, greater<ll>());
    sort(b, b+n);
    ll lo= 0, hi= 1000000000001ll, res, cnt= 100;
    while(lo<=hi && cnt--)
    {
        ll mid= (lo+hi)>>1;
        if(chck(n, k, mid))res= mid, hi= mid-1;
        else lo= mid+1;
    }
    printf("%lld\n", res);
    return 0;
}
