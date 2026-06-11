#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#define ls id << 1
#define rs id << 1 | 1
using namespace std;
typedef long long ll;
int n, k;
const int N = 100050;
const ll mod = 1e9 + 7;
ll ans = 1;
struct edge
{
    int v, nxt;
} e[N << 1];
int col[N];
int dep[N];
int head[N], ecnt;
ll a[N];
int f[N], son[N];
void ad(int u, int v)
{
    e[++ecnt].v = v;
    e[ecnt].nxt = head[u];
    head[u] = ecnt;
}

void dfs1(int u, int fa)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        f[v] = u;
        son[u]++;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
    }
}
void dfs2(int u, int fa, ll val)
{
    int t = son[u], nv = k;
    t--;
    a[u] = val;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        if (dep[v] <= 1)
        {
            dfs2(v, u, --nv);
        }
        else
        {
            dfs2(v, u, k - 2 - t);
            t--;
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        ad(x, y), ad(y, x);
    }
    dfs1(1, 0);
    dfs2(1, 0, k);
    for (int i = 1; i <= n; ++i)
    {
        ans *= a[i];
        ans %= mod;
    }
    printf("%lld\n", ans);
    // system("pause");
    return 0;
}