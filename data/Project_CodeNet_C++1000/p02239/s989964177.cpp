#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <vector>
#include <list>
#define inf 200
using namespace std;

int n;
list<int> adj[101];
int d[101];
bool f[101];
void BFS(int v)
{
    int m = 0;
    f[v] = false;
    while (!adj[v].empty())
    {
        d[adj[v].front()] = min(d[v] + 1, d[adj[v].front()]);
        adj[v].pop_front();
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i] && d[i] < d[m])
            m = i;
    }
    if (m > 0)
        BFS(m);
}

void print()
{
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == inf)
            d[i] = -1;
        printf("%d %d\n", i, d[i]);
    }
}

int main()
{
    int u, k, v;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        d[i] = inf;
        f[i] = true;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> u >> k;
        while (k > 0)
        {
            cin >> v;
            adj[u].push_back(v);
            k--;
        }
    }
    d[1] = 0;
    BFS(1);

    print();

    return 0;
}
