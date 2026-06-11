#include <stdio.h>
#include <string.h>
using namespace std;
bool b[105][105];
char a[105][105];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int n,m,res;
int init()
{
    for (int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
}
void dfs(int p1,int p2)
{
    b[p1][p2]=1;
    for (int i=0;i<4;i++)
    {
        int d1=p1+dx[i],d2=p2+dy[i];
        if (d1>=0 && d1<n && d2>=0 && d2<m && b[d1][d2]==0 && a[d1][d2]==a[p1][p2])
            dfs(d1,d2);
    }
}
void solve()
{
    memset(b,0,sizeof(b));res=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (!b[i][j])
            {
                ++res;
                dfs(i,j);
            }
        }
    }
}
int main()
{
    while (scanf("%d%d",&n,&m)==2 && n!=0 && m!=0)
    {
        init();
        solve();
        printf("%d\n",res);
    }
}