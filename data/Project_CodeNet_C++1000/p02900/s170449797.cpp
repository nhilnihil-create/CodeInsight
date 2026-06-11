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
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
    printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
    system("pause");
#endif
}
ll a, b;
ll ans;
ll pri[N * 2], tot;
ll vis[N * 2];
void shaipri()
{
    for (int i = 2; i <= 1000000; ++i)
    {
        if (!vis[i])
            vis[i] = i, pri[++tot] = i;
        for (int j = 1; j <= tot && i * pri[j] <= 1e6; ++j)
        {
            vis[i * pri[j]] = pri[j];
            if (i % pri[j] == 0)
                break;
        }
    }
}

void solve()
{
    shaipri();
    cin >> a >> b;
    ll g = __gcd(a, b);
    ans = 1;
    for (int i = 1; i <= tot; ++i)
    {
        if (g % pri[i] == 0)
        {
            ans++;
            while (g % pri[i] == 0)
                g /= pri[i];
        }
    }
    ans += (g > 1);
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