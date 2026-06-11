#include<cstdio> 
#include<cstring>
const int MAX=110;
char maze[MAX][MAX];
int d[MAX][MAX];
int n,m;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void dfs(int x,int y,char c)
{
	if(x>=0 && x<n && y>=0 && y<m && maze[x][y]==c && !d[x][y])
		{
			d[x][y]=1;
			for(int i=0;i<4;i++)
			{
				int nx=x+dx[i],ny=y+dy[i];
				dfs(nx,ny,c);
			}
		}
		else
		return;
}
int main()
{
	while(~scanf("%d %d",&n,&m) && (n||m))
	{
		int sum=0;
		memset(d,0,sizeof(d));
		for(int i=0;i<n;i++)
			scanf("%s",maze[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				{
				if(!d[i][j])
					{
						char c=maze[i][j];
						dfs(i,j,c),sum++;
					}
				else
				continue;
				}
		printf("%d\n",sum);
	}
	return 0;
 } 