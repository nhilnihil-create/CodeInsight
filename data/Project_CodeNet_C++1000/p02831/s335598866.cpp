#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
ll gcd(ll a,ll b)
{
    if (b==0LL)
    return a;
    return (gcd(b,a%b));
}
int main()
{
    ll a,b;
    scanf("%lld%lld",&a,&b);
    ll g=gcd(a,b);
    ll val=(a*b)/g;
    printf("%lld\n",val);
    return 0;
}
