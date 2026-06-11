
#include <cstdio>
#include <cstring>

const int MAXN = 105;
char map[MAXN][MAXN];
int n, m;
int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int dfs(int px, int py, char c)
{
    map[px][py] = ' ';
    for(int i = 0; i < 4; i++)
    {
        int x = px + d[i][0];
        int y = py + d[i][1];
        if(x >= 0 && x < n && y >=0 && y < m
           && c == map[x][y])
           dfs(x, y, c);
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        if(0 == n && 0 == m) break;
        getchar();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%c", &map[i][j]);
            }
            getchar();
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(' ' != map[i][j])
                {
                    dfs(i, j, map[i][j]);
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}