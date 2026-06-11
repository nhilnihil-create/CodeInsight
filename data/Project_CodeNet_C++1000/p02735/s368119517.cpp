#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
int dis[101][101];
typedef pair<int, int>pi;
queue<pi>q;
int dirx[]= {0, 1};
int diry[]= {1, 0};
char str[101][101];
int main()
{
    int h, w;
    scanf("%d %d", &h, &w);
    for(int i=1; i<=h; i++)
    scanf("%s", str[i]+1);
    for(int i=1; i<=h; i++)
    for(int j=1; j<=w; j++)
    dis[i][j]= h+w;
    dis[1][1]= (str[1][1]=='#');
    q.push({1, 1});
    while(!q.empty())
    {
        int x= q.front().xx;
        int y= q.front().yy;
        q.pop();
        for(int i=0; i<2; i++)
        {
            int x1= x+dirx[i];
            int y1= y+diry[i];
            if(x1>=1 && x1<=h && y1>=1 && y1<=w)
            {
                if(str[x1][y1]=='.')
                {
                    if(dis[x1][y1]>dis[x][y])
                    dis[x1][y1]= dis[x][y], q.push({x1, y1});
                }
                else
                {
                    if(dis[x1][y1]>dis[x][y]+(str[x][y]=='.'))
                    dis[x1][y1]= dis[x][y]+(str[x][y]=='.'), q.push({x1, y1});
                }
            }
        }
    }
    printf("%d\n", dis[h][w]);
    return 0;
}
