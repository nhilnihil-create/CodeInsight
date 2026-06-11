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

bool solve(int b[][3])
{
    int n=3;

    // row 
    for (int i=0;i<n;i++)
    {
        int c=0;
        for (int j=0;j<n;j++)
        {
            if (b[i][j])
            {
                c++;
            }
        }
        if (c==3)
        {
            return true;
        }
    }

    // col 
    for (int i=0;i<n;i++)
    {
        int c=0;
        for (int j=0;j<n;j++)
        {
            if (b[j][i])
            {
                c++;
            }
        }
        if (c==3)
        {
            return true;
        }
    }

    // diagonal
    if (b[0][0]&&b[0][0]==b[1][1]&&b[1][1]==b[2][2])
    {
        return true;
    }
    if (b[0][2]&&b[0][2]==b[1][1]&&b[1][1]==b[2][0])
    {
        return true;
    }
    return false;
}
int main()
{
    start();
    unordered_map<int, pair<int, int>> a;
    int n=3;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            a[x]={ i, j };
        }
    }
    int b[3][3];
    memset(b, 0, sizeof(b));
    int m;
    cin>>m;
    int x;
    for (int i=0;i<m;i++)
    {
        cin>>x;
        if (a.find(x)!=a.end())
        {
            b[a[x].first][a[x].second]=1;
        }
    }
    if (solve(b))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }


    return 0;
}