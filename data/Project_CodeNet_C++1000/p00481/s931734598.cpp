#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAX = 1200;
int H,W,N;
int sx,sy,res;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};//4个?找方向
char map[MAX][MAX];
int d[MAX][MAX];//??最短路的数?
typedef pair<int,int> P;
void BFS(int x,int y,char m)
{
    queue<P>  que;
    //初始状?入?
    que.push(P(x,y));
    d[x][y]=0;
    while(que.size())
    {
        //从?列最前端取出状?
        P p = que.front();
        que.pop();
        //若到?m点?束?找
        if(map[p.first][p.second]==m){
            sx=p.first;
            sy=p.second;
            return;
        }

        //四个方向循?
        for(int i=0;i<4;i++)
        {
            //?算移?后的位置
            int nx=p.first+dx[i];
            int ny=p.second+dy[i];
            if(nx>=0&&nx<H&&ny>=0&&ny<W&&map[nx][ny]!='X'&&d[nx][ny]==-1)
            {
                que.push(P(nx,ny));
                d[nx][ny]=d[p.first][p.second]+1;
            }
        }
    }

}
void solve()
{
    for(int i=1;i<=N;i++)
    {
        memset(d,-1,sizeof(d));
        BFS(sx,sy,i+48);
        res+=d[sx][sy];
    }
    printf("%d\n",res);
}
int main()
{
    scanf("%d%d%d",&H,&W,&N);
    for(int i=0;i<H;i++)
        scanf("%s",map[i]);

    for(int i=0;i<H;i++)
    for(int j=0;j<W;j++)
    {
        if(map[i][j]=='S')
        {
            sx=i;sy=j;
            i=H;j=W;
        }
    }
    solve();
    return 0;
}