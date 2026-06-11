#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
using namespace std;
const int N = 100050;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
    printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
    system("pause");
#endif
}
ll n, k;
ll ans;
ll f[N];
inline ll mi(ll a, ll b)
{
    ll ret = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            ret *= a, ret %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return ret;
}

void solve()
{
    scanf("%lld%lld", &n, &k);
    for (ll i = k; i; --i)
    {
        f[i] = mi(k / i, n);
        for (ll j = i * 2; j <= k; j += i)
            f[i] -= f[j];
        ans += ((i * f[i] + mod) % mod) % mod;
        ans = (ans + mod) % mod;
    }
    cout << ans << '\n';
}

int main()
{
    TIME_START = clock();
    int Test = 1;
    // cin >> Test;
    while (Test--)
        solve();
    TIME_END = clock();
    program_end();
    return 0;
}