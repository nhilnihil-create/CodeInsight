# include <iostream>
# include <cstring>
using namespace std;

char grid[105][105];
int H, W;
int memo[105][105];

bool inside (int x, int y)
{
    if (x>H || y>W || x<1 || y<1)
    {
        return false;
    }

    return true;
}

int findroute(int x, int y)
{
    if (!inside(x, y))
    {
        return 1000000000;
    }

    if (memo[x][y]!=-1)
    {
        return memo[x][y];
    }

    if (x==H && y==W)
    {
        if (grid[x][y]=='#')
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }

    if (grid[x][y]=='.')
    {
        return memo[x][y]=min(findroute(x+1, y), findroute(x, y+1));
    }

    else if (grid[x][y]=='#')
    {
        return memo[x][y]=min(findroute(x+1, y)+(grid[x+1][y]=='.'), findroute(x, y+1)+(grid[x][y+1]=='.'));
    }
}

int main()
{
    memset(memo, -1, sizeof(memo));

    cin>>H>>W;

    for (int i=1; i<=H; i++)
    {
        for (int j=1; j<=W; j++)
        {
            cin>>grid[i][j];
        }
    }

    cout<<findroute(1, 1)<<endl;
}