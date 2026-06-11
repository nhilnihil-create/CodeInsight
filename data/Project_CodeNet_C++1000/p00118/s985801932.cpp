#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 105;
int n,m;
char a[maxn][maxn];
int xx[4]={0,0,-1,1};
int yy[4]={1,-1,0,0};
int num;
int sx,sy;
char ch;
void dfs(int x,int y)
{
    a[x][y]='.';
    for(int ii=0;ii<4;ii++)
    {
        int nx=x+xx[ii];
        int ny=y+yy[ii];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&a[nx][ny]==ch&&a[nx][ny]!='.')
        {
            dfs(nx,ny);
        }
    }
    return ;
}
int main()
{

    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",a[i]);
            getchar();
        }
        num=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            if(a[i][j]=='#'||a[i][j]=='*'||a[i][j]=='@')
            {
                 ch=a[i][j];
                 //sx=i;sy=j;
                dfs(i,j);num++;
            }
        }
        printf("%d\n",num);
         /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
        {
            printf("%c",a[i][j]);
        }
        cout<<endl;
        }*/
    }
    return 0;
}