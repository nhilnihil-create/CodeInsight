#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int N = 100 + 5;

int n,m;
int mp[N][N];
int dirx[] = {0, 1, 0, -1};
int diry[] = {1, 0, -1, 0};
int apple, pear, orange;

void dfs(int x, int y, int color)
{
    mp[x][y] = 0;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dirx[i], ny = y + diry[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(mp[nx][ny] == color)
            dfs(nx, ny, color);
    }
}


int main()
{
    while(scanf("%d%d", &n, &m), n || m)
    {
        apple = pear = orange = 0;
        char ch;
        getchar();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%c", &ch);
                if(ch == '@') mp[i][j] = 1;
                else if(ch == '#') mp[i][j] = 2;
                else if(ch == '*') mp[i][j] = 3;
            }
            getchar();
        }


        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mp[i][j] == 1)
                {
                    apple++;
                }
                else if(mp[i][j] == 2)
                {
                    pear++;
                }
                else if(mp[i][j] == 3)
                {
                    orange++;
                }
                else
                    continue;
                dfs(i, j, mp[i][j]);
            }
        }
        printf("%d\n", apple+pear+orange);
    }
    return 0;
}