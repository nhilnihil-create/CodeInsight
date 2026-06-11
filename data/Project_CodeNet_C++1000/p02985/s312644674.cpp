#include <bits/stdc++.h>
#define N 1000099
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define LL long long
// ios::sync_with_stdio(false);
using namespace std;
int n, num;
int head[N];
LL K, ans;
struct edge
{
    int v, nxt;
} ed[N];
void add(int u, int v)
{
    ed[++num].nxt = head[u];
    ed[num].v = v;
    head[u] = num;
}
void dfs(int u, int fa, int dep)
{
    int st = 0;
    if (dep)
        st = K - 2;
    else
        st = K - 1;
    for (int i = head[u]; i; i = ed[i].nxt)
    {
        int v = ed[i].v;
        if (v == fa) continue;
        ans = (ans * st) % MOD;
        st--;
        dfs(v, u, dep + 1);
    }
}
int main()
{
    cin >> n >> K;
    for (int i = 1, x, y; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    ans = K;
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
