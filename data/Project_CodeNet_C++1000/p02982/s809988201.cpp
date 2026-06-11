#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
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

int main()
{
    start();
    int n, m;
    cin>>n>>m;
    int a[n][m];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int c=0;
    for (int k=0;k<n-1;k++)
    {
        for (int i=k+1;i<n;i++)
        {
            int x=0;
            for (int j=0;j<m;j++)
            {
                x+=pow(a[i][j]-a[k][j], 2);
            }
            if (sqrt(x)==floor(sqrt(x)))
            {
                c++;
            }
        }
    }
    cout<<c;
    return 0;
}