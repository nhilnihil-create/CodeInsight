#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define fi(i, n) for( int i=0 ; i<n ; i++ )
#define f(i, a, b) for( int i=a ; i<b ; i++ )
#define vi vector<int>
#define pb push_back
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}
ll fact(ll n)
{
    ll ans = 1e14;
    for(ll i = 1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            ll sol = (i - 1) + (n/i - 1);
            ans = min(ans,sol);
        }
    }
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    ll ans = fact(n);
    cout<<ans<<endl;

}
