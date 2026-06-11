#include<bits/stdc++.h>
#define ll long long
#define S second
#define F first

using namespace std;

const int N = 1e5 + 15, M = 2 * N;

#define arr(t, n, s, e) t _##n[e-s+1], *n= _##n+(-s);

int head[N], nxt[M], to[M], col[M], deg[N], ne;

void addEdge(int f, int t)
{
    nxt[ne] = head[f];
    to[ne] = t;
    deg[f]++;
    head[f] = ne++;
}

void addBiEdge(int f, int t)
{
    addEdge(f, t);
    addEdge(t, f);
}

void dfs(int u, int prvC = M)
{
    int c = 1;
    for(int e = head[u] ; ~e ; e = nxt[e])
    {
        if(col[e]) continue;
        if(c == prvC) c++;
        int v = to[e];
        col[e] = col[e ^ 1] = c;
        dfs(v, c++);
    }
}

int main()
{
    memset(head, -1, sizeof head);
    int n, t, u, v, mx = 0;
    scanf("%d", &n);
    for(int i = 1 ; i < n ; i++)
    {
        scanf("%d%d", &u, &v);
        addBiEdge(u, v);
        mx = max({mx, deg[u], deg[v]});
    }
    dfs(1);
    printf("%d\n", mx);
    for(int i = 0 ; i < ne ; i += 2)
    {
        printf("%d\n", col[i]);
    }
    return 0;
}