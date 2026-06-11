#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl "\n"
#define pll pair<ll, ll>
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pair<int, int>>
#define mems(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define forn(i, s, e) for (int i = s; i < (e); ++i)
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define FILEIO                          \
    freopen("./input.txt", "r", stdin); \
    freopen("./output.txt", "w", stdout);
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d)                                                               \
    for (                                                                       \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second;                                                       \
        debug("%s : %lld ms\n ", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false)
const int M = 998244353;

template <class T>
T ABS(const T &x) { return x > 0 ? x : -x; }
ll inv(ll a, ll b) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }
ll gcd(ll n1, ll n2) { return n2 == 0 ? ABS(n1) : gcd(n2, n1 % n2); }
ll lcm(ll n1, ll n2) { return n1 == 0 && n2 == 0 ? 0 : ABS(n1 * n2) / gcd(n1, n2); }

ll Pow(ll a, ll b)
{
    ll x = 1, y = a;
    while (b > 0)
    {
        if (b % 2)
        {
            x = x * y;
            if (x > M)
                x %= M;
        }
        y = y * y;
        if (y > M)
            y %= M;
        b /= 2;
    }
    return x;
}

int main()
{
    FASTIO
#ifdef LOCAL
    FILEIO
#endif
    int n, s;
    cin >> n >> s;
    int dp[n + 1][s + 1], a[n + 1];
    forn(i, 0, n)
    {
        cin >> a[i];
    }
    forn(i, 0, n + 1) forn(j, 0, s + 1) dp[i][j] = 0;
    ll inv2 = inv(2, M);
    dp[0][0] = Pow(2, n);
    forn(i, 0, n)
    {
        forn(j, 0, s + 1)
        {
            dp[i + 1][j] = (dp[i][j] + dp[i + 1][j]) % M;
            if (j + a[i] <= s)
            {
                dp[i + 1][j + a[i]] = (dp[i + 1][j + a[i]] + (dp[i][j] % M * inv2) % M) % M;
            }
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}