#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    ll n;
    scanf("%lld",&n);
    ll mini=1000000000000000000;
    for (ll i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            ll val1=i;
            ll val2=(n/i);
            mini=min(mini,(val1+val2-2));
        }
    }
    printf("%lld\n",mini);
    return 0;
}