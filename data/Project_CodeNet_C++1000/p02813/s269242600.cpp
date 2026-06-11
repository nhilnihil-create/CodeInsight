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

bool check_1(int* a, int* b, int n)
{
    for (int i=0;i<n;i++)
    {
        if (a[i]!=b[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    start();
    int n;
    cin>>n;
    int t[n];
    for (int i=0;i<n;i++)
    {
        t[i]=i+1;
    }
    int a[n];
    for (int i=0;i<n;i++)
    {
        a[i]=t[i];
    }
    int b[n], c[n];
    for (int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for (int i=0;i<n;i++)
    {
        cin>>c[i];
    }

    int d=0;
    do
    {
        d++;
        if (check_1(a, b, n))
        {
            break;
        }
    } while (next_permutation(a, a + n));
    int e=0;
    for (int i=0;i<n;i++)
    {
        a[i]=t[i];
    }
    do
    {
        e++;
        if (check_1(a, c, n))
        {
            break;
        }
    } while (next_permutation(a, a + n));
    cout<<abs(e-d);
    return 0;
}