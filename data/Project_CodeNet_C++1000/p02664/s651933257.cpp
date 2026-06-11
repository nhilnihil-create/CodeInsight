#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define be begin()
#define en end()
#define le length()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repo(i, n) for (ll i = 1; i <= n; i++)
#define foreach(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define eps 1e-6
#define pi 3.141592653589793
#define c(a) cout << a << "\n";
#define ao(a)        \
    for (auto i : a) \
        cout << i << " ";
#define endl '\n'
typedef vector<int> vii;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 6e5 + 4;

ll powmod(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

ll gcd(ll a, ll b)
{
    while (b > 0)
    {
        ll t = a % b;
        a = b, b = t;
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

ll is_prime(ll n)
{
    if (n <= 1 || n > 3 && (n % 2 == 0 || n % 3 == 0))
        return 0;
    for (ll i = 5, t = 2; i * i <= n; i += t, t = 6 - t)
        if (n % i == 0)
            return 0;
    return 1;
}
ll modI(ll a, ll m)
{
    ll m0 = m, y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

long long mod_inv(long long a, long long m = MOD)
{
    return a == 1 ? 1 : m - mod_inv(m % a, a) * m / a;
}

long long choose(long long n, long long r)
{
    long long product = 1;

    for (long long i = 0; i < r; i++)
        product = product * (n - i) % MOD * mod_inv(i + 1) % MOD;

    return product;
}

int bit[N];

// void init(void){
//     int i;
//     rep(i,(1<<20)) v[i] = 0;
// }

void update(int idx, int val)
{
    while (idx <= N)
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int pref(int idx)
{
    int ans = 0;
    while (idx > 0)
    {
        ans += bit[idx];
        idx -= idx & -idx;
    }
    return ans;
}
// long long get(vector<long long> &f, int pos) {
//     long long res = 0;
//     for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
//         res += f[pos];
//     return res;
// }

// void upd(vector<long long> &f, int pos, int val) {
//     for (; pos < int(f.size()); pos |= pos + 1) {
//         f[pos] += val;
//     }
// }
// int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
// int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
// int dx[4]={-1, +1, 0, 0};
// int dy[4]={0, 0, +1, -1};
/*************************************************************************************************************/
int main()
{
    string s;
    cin >> s;
    rep(i, s.le)
    {
        if (s[i] == '?')
            cout << "D";
        else
            cout << s[i];
    }

    return 0;
}