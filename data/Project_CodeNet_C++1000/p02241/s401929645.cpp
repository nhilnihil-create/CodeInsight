#include <bits/stdc++.h>
using namespace std;
#define N 100
int G[N][N];
int n;

int prim()
{
    int visited[n];
    int d[n];
    int p[n];

    for (int i; i < n; i++)
    {
        visited[i] = 0;
        d[i] = 114514;
    }

    d[0] = 0;
    p[0] = -1;

    while (true)
    {
        int mincost = 114514;
        int u;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && d[i] < mincost)
            {
                mincost = d[i];
                u = i;
            }
        }

        if (mincost == 114514)
            break;

        visited[u] = 1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && G[u][i] != -1)
            {
                if (G[u][i] < d[i])
                {
                    d[i] = G[u][i];
                    p[i] = u;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 1; i < n; i++)
        sum += d[i];
    return sum;
}

int main()
{
    cin >> n;
    int a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            if (a == -1)
                G[i][j] = 114514;
            else
                G[i][j] = a;
        }
    }
    cout << prim() << endl;
}
