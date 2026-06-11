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
const int N = 200050;
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
int n, k, c;
char s[N];
int vis[N];

void solve()
{
    scanf("%d%d%d", &n, &k, &c);
    scanf("%s", s + 1);
    int cnt = 0;
    int now = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 'o' && now == 0)
        {
            cnt++;
            now = c;
            vis[i]++;
        }
        else
            now = max(now - 1, 0);
    }
    if (cnt > k)
        return;
    now = 0;
    cnt = 0;
    for (int i = n; i >= 1; --i)
    {
        if (s[i] == 'o' && now == 0)
        {
            cnt++;
            now = c;
            vis[i]++;
        }
        else
            now = max(now - 1, 0);
    }
    if (cnt > k)
        return;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == 2)
            printf("%d\n", i);
    }
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