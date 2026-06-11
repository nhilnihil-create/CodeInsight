#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, m, t, s;

int a[N][N];

void rec(int x, int y)
{
    if (x == n)
    {
        for (int i = 0; i < n; ++i)
        {
            int q[2] = {};
            for (int j = 0; j < m; ++j)
            {
                q[a[i][j]]++;
            }
            if (min(q[0], q[1]) != t)
                return;
        }
        for (int j = 0; j < m; ++j)
        {
            int q[2] = {};
            for (int i = 0; i < n; ++i)
            {
                q[a[i][j]]++;
            }
            if (min(q[0], q[1]) != s)
                return;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                printf("%d", a[i][j]);
            printf("\n");
        }
        exit(0);
    }
    a[x][y] = 0;
    if (y == m - 1)
        rec(x + 1, 0);
    else
        rec(x, y + 1);
    a[x][y] = 1;
    if (y == m - 1)
        rec(x + 1, 0);
    else
        rec(x, y + 1);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &t, &s);
    for (int i = 0; i < n; ++i)
    {
        if (i < s)
        {
            for (int j = 0; j < m; ++j)
            {
                if (j < t)
                    printf("1");
                else
                    printf("0");
            }
        }
        else
        {
            for (int j = 0; j < m; ++j)
            {
                if (j < t)
                    printf("0");
                else
                    printf("1");
            }
        }
        printf("\n");
    }
    return 0;
    rec(0, 0);
    printf("-1\n");
    return 0;
}
