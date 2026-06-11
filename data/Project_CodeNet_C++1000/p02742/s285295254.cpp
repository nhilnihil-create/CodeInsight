#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#include <bitset>
#define M 1000000007
#define M1 998244353

#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

ll power(ll x, ll n)
{
    ll result = 1;
    while (n)
    {
        if (n % 2 == 1)
            result = result * x;
        n = n / 2;
        x = x * x;
    }
    return result;
}

ll gcd(ll a, ll b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

inline ll mul(ll x, ll y, ll m)
{
    ll z = 1LL * x * y;
    if (z >= m)
    {
        z %= m;
    }
    return z;
}

ll powmod(ll x, ll y, ll m)
{
    ll r = 1;
    while (y)
    {
        if (y & 1)
        {
            r = mul(r, x, m);
        }
        y >>= 1;
        x = mul(x, x, m);
    }
    return r;
}



void start()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
/***********************************************************************************************************/

ll solve(ll h, ll w)
{
    if (h==1||w==1)
    {
        return 1;
    }
    ll ans=0, a=0, b=0;
    if (w%2!=0)
    {
        a=w/2+1;
    }
    else
    {
        a=w/2;
    }
    b=w/2;
    if (h%2==0)
    {
        ans=(h/2)*(a+b);
    }
    else
    {
        ans=((h/2+1)*a)+((h/2)*b);
    }
    return ans;

}
int main()
{
    start();
    ll h, w;
    cin>>h>>w;
    cout<<solve(h, w);
    return 0;
}