#include<iostream>
#include<stdio.h>
using namespace std;
char a[105][105];
bool b[105][105];
int m,n;
int dire[4][2]={0,1,0,-1,1,0,-1,0};
void dfs(int x,int y)
{
    b[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int x1=x+dire[i][0];
        int y1=y+dire[i][1];
        if(x1>=0 && x1<m && y1>=0 && y1<n && !b[x1][y1] &&a[x1][y1]==a[x][y])
        {
            dfs(x1,y1);
        }
    }
}
int main()
{
    int ans;
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(m==0||n==0)
            return 0;
        ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
                b[i][j]=false;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!b[i][j])
                {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}