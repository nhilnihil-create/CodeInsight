#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,n,a) for(int i=n;i>a;i--)
#define mem0(x) memset(x,0,sizeof(x))
#define memff(x) memset(x,0xff,sizeof(x))
#define INF 100000000
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
int w,h,n;
int sw[15],sh[15];
char maze[1024][1024];
int d[1024][1024];
int dw[4]={0,1,0,-1},dh[4]={1,0,-1,0};
int BFS(int sw,int sh,int gw,int gh)
{
    queue<P> que;
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=h;j++)
        {
            d[i][j]=INF;
        }
    }
    que.push(P(sw,sh));
    d[sw][sh]=0;
    while(que.size())
    {
        P p=que.front();
        que.pop();
        if(p.first==gw&&p.second==gh)break;
        for(int i=0;i<4;i++)
        {
            int nw=p.first+dw[i],nh=p.second+dh[i];
            if(1<=nw&&nw<=w&&1<=nh&&nh<=h&&maze[nw][nh]!='X'&&d[nw][nh]==INF)
            {
                que.push(P(nw,nh));
                d[nw][nh]=d[p.first][p.second]+1;
            }
        }
    }
    return d[gw][gh];
}
int main()
{
    //freopen("input.in","r",stdin);
    while(cin>>w>>h>>n)
    {
        int ans=0;
        for(int i=1;i<=w;i++)
        {
            for(int j=1;j<=h;j++)
            {
                cin>>maze[i][j];
                if(maze[i][j]=='S')
                {
                    sw[0]=i;sh[0]=j;
                }
            }
        }
        for(int i=1;i<=w;i++)
        {
            for(int j=1;j<=h;j++)
            {
                if(maze[i][j]>48&&maze[i][j]<58)
                {
                    sw[maze[i][j]-48]=i;
                    sh[maze[i][j]-48]=j;
                }
            }
        }
        for(int i=0;i<=n-1;i++)
        {
            ans+=BFS(sw[i],sh[i],sw[i+1],sh[i+1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}