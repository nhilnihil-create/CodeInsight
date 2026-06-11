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
ll dp[1015][st(12) + 5];
int n, m;
struct keys
{
    ll cost;
    int state;
} a[1050];

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int b;
        scanf("%lld", &a[i].cost);
        scanf("%d", &b);
        while (b--)
        {
            int x;
            scanf("%d", &x);
            a[i].state |= st(x - 1);
        }
    }
    memarray(dp, llinf);
    dp[0][0] = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int s = 0; s < st(n); ++s)
        {
            dp[i][s | a[i].state] = min(dp[i][s | a[i].state], dp[i - 1][s] + a[i].cost);
            dp[i][s] = min(dp[i][s], dp[i - 1][s]);
        }
    }
    ll ans = llinf;
    for (int i = 0; i <= m; ++i)
    {
        ans = min(ans, dp[i][st(n) - 1]);
    }
    if (ans == llinf)
        ans = -1;
    cout << ans;
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