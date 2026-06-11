#include <stdio.h>
#include <string.h>
#define ms(a) memset(a,'\0',sizeof(a))

int x,y,ans,l,p,m;
char map[105][105];

void dfs(int xx,int yy,char c)
{
	if(xx>=0 && xx<x && yy>=0 && yy<y && map[xx][yy]==c)
	{
		map[xx][yy]='.';
	}
	else
		return ;
	dfs(xx-1,yy,c);
	dfs(xx+1,yy,c);
	dfs(xx,yy+1,c);
	dfs(xx,yy-1,c);
}

int main()
{
	//freopen("Aizu0118.txt","r",stdin);
	scanf("%d %d",&x,&y);
	while(!(x==0&&y==0))
	{
		l=p=m=0;
		ans=0;
		getchar();
		for(int i=0;i<x;i++)
		{
			gets(map[i]);
		}
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
				if(map[i][j]!='.')
				{
					dfs(i,j,map[i][j]);
					ans++;
				}
			}
		}
		printf("%d\n",ans);
		scanf("%d %d",&x,&y);
	}
	return 0;
}