#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 2e5 + 10;
int N, u[maxn], v[maxn];
int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N - 1; i++)
        scanf("%d %d", &u[i], &v[i]);
    LL ans = 0;
    for(int i = 1; i <= N; i++)
        ans += (LL) i * (N - i + 1);
    for(int i = 1; i <= N - 1; i++)
    {
        if(u[i] > v[i])
            swap(u[i], v[i]);
        ans -= (LL) u[i] * (N - v[i] + 1);
    }
    printf("%lld\n", ans);
    return 0;
}
