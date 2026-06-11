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
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
    printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
    system("pause");
#endif
}
int n;
ll a[85];
ll ans = 1000;

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    int i = 1;
    while (i < n)
    {
        int j = i;
        while (j <= n && a[j] >= a[j + 1])
            j++;
        if (j == n + 1)
            break;
        ll cnt = ans / a[j];
        ans = ans - cnt * a[j] + cnt * a[j + 1];
        i = j + 1;
    }
    printf("%lld\n", ans);
}

int main()
{
    TIME__START = clock();
    int Test = 1;
    // scanf("%d", &Test);
    while (Test--)
        solve();
    TIME__END = clock();
    program_end();
    return 0;
}