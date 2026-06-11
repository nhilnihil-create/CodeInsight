#include <bits/stdc++.h>
using namespace std;

#define sint(a) scanf("%d", &a)
#define sint2(a, b) scanf("%d %d", &a, &b)
#define sll(a) scanf("%lld", &a)
#define sll2(a, b) scanf("%lld %lld", &a, &b)
#define mem(a, i) memset(a, i, sizeof(a))
#define pb push_back
#define int long long
#define ll long long
#define lson node << 1
#define rson (node << 1) + 1
#define endl "\n"

const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
const double pi = acos(-1);

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int qpow(int a, int n)
{
    int b = 1;
    while (n)
    {
        if (n & 1)
            b = a * b % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return b;
}

class Prime_Number
{
public:
    int prime[maxn], s, v[maxn];
    void prime_init(int n)
    {
        for (int i = 2; i <= n; i++)
        {
            if (!v[i])
            {
                prime[s++] = i;
                for (int j = 1; j * i <= n; j++)
                    v[i * j] = 1;
            }
        }
    }
};

//**************************
int a[maxn];
void solve()
{
    ll n;
    cin>>n;
    int ans=1,ok=1;
    ll k=7;
    while(k%n)
    {
        k=k*10+7;
        k%=n;
        ans++;
        a[k]++;
        if(a[k]==2)
            {
                ok=0;
                break;
            }
    }
    if(ok)
    cout<<ans;
    else 
        cout<<-1;
}
signed main()
{
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}
