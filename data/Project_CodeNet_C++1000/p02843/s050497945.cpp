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

int solve(int *a, int n, int s, vector<vector<int>> &v)
{
    if (s==0)
    {
        return v[n][s]=1;
    }
    if (n==0)
    {
        return v[n][s]=0;
    }
    if (v[n][s]!=-1)
    {
        return v[n][s];
    }
    if (a[n-1]<=s)
    {
        return v[n][s]=solve(a, n, s-a[n-1], v)||solve(a, n-1, s, v);
    }
    return v[n][s]=solve(a, n-1, s, v);
}
int main()
{
    start();
    int x;
    cin>>x;
    int a[]={ 100, 101, 102, 103, 104, 105 };
    int n=6;
    vector<vector<int>> v(n+1, vector<int>(x+1, -1));
    if (solve(a, n, x, v))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }

    return 0;
}