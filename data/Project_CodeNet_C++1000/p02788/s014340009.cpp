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
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
    printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
    system("pause");
#endif
}
int n;
ll D, A;
struct monsters
{
    ll x, h;
    bool operator<(const monsters &X) const
    {
        return x < X.x;
    }
} a[N];
ll mark[N];

void solve()
{
    scanf("%d%lld%lld", &n, &D, &A);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &a[i].x, &a[i].h);
    sort(a + 1, a + n + 1);
    int las = 1;
    int i = 1;
    ll ans = 0;
    ll delta = 0;
    while (las <= n)
    {
        while ((a[i + 1].x - a[las].x > 2ll * D || i == n) && las <= n)
        {
            ll cnt = max(0ll, a[las].h / A + (a[las].h % A > 0));
            mark[i] += -cnt * A;
            ans += cnt;
            delta += cnt * A;
            a[las].h -= delta;
            delta += mark[las];
            las++;
            while (las <= n)
            {
                a[las].h -= delta;
                delta += mark[las];
                mark[las] = 0;
                if (a[las].h > 0)
                    break;
                las++;
            }
        }
        i = min(i + 1, n);
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