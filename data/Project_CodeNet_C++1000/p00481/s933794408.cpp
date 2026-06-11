#include "cstring"
#include "cstdio"
#include "queue"
using namespace std;

const int maxn=1024;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

char mp[maxn][maxn];
int vis[maxn][maxn];
int wx[10],wy[10];
int n,m,k;

int bfs(int x1,int y1,int x2,int y2)
{
	memset(vis,0,sizeof(vis));
	queue<int>qx;qx.push(x1);
	queue<int>qy;qy.push(y1);
	queue<int>qt;qt.push(0);
	vis[x1][y1]=1;
	
	while(!qx.empty())
	{
		int nx=qx.front();qx.pop();
		int ny=qy.front();qy.pop();
		int nt=qt.front();qt.pop();
		
		if(nx==x2 && ny==y2)return nt;
		
		for(int i=0;i<4;i++)
		{
			int px=nx+dx[i];
			int py=ny+dy[i];
			if(px>=0 && py>=0 && px<n && py<m && mp[px][py]!='X' && !vis[px][py])
			{
				qx.push(px);
				qy.push(py);
				qt.push(nt+1);
				vis[px][py]=1;
			}
		}
		
	}
	
	return 0;
}

int main()
{
	//freopen("f.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			mp[i][j]=getchar();
			while(mp[i][j]=='\n' || mp[i][j]=='\0')mp[i][j]=getchar();
			if(mp[i][j]>='1' && mp[i][j]<='9')
			{
				wx[mp[i][j]-'0']=i;
				wy[mp[i][j]-'0']=j;
			}
			if(mp[i][j]=='S')
			{
				wx[0]=i;
				wy[0]=j;
			}	
		}
	int ans=0;
	for(int i=0;i<k;i++)
		ans+=bfs(wx[i],wy[i],wx[i+1],wy[i+1]);
	printf("%d\n",ans);
	return 0;
} 
