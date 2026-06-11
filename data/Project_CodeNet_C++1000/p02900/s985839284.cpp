#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
using namespace std;
#define ll long long
#define db double
ll gcd(ll a,ll b)
{
    return b>0?gcd(b,a%b):a;
}
int main()
{

    ll a,b;
    scanf("%lld %lld",&a,&b);
    ll k=gcd(a,b);
    ll ans=1;
    for(ll i=2;i*i<=k;i++)
    {
        if(k%i==0)
        {
            ans++;
            while(k%i==0)
            {
                k=k/i;
            }
        }
    }
    if(k>1)ans++;
    printf("%lld",ans);
    return 0;
}
