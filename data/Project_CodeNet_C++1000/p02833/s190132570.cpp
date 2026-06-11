#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
ll Power(ll a,int b)
{
    ll res=1LL;
    while (b>0LL)
    {
        if (b%2LL==1LL)
        res=res*a;
        a=a*a;
        b=b/2LL;
    }
    return res;
}
int main()
{
    ll n;
    scanf("%lld",&n);
    if (n<=0LL || n%2LL==1LL)
    {
        printf("0\n");
        return 0;
    }
    ll sum1=0;
    for (ll i=25;i>0;i--)
    {
        ll p=2LL*Power(5,i);
        sum1=sum1+(n/p);
    }
    printf("%lld\n",sum1);
    return 0;
}
