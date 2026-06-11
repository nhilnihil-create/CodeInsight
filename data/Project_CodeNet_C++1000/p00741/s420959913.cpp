#include<iostream>
using namespace std;
int dx[]={0,1,0,-1,1,1,-1,-1},dy[]={1,0,-1,0,1,-1,1,-1};
struct E{
	int w,h;
	int ma[50][50],color[50][50];
	bool used[50][50];
	int col;
	int init(int _w,int _h)
	{
		w=_w,h=_h;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				cin>>ma[i][j];
				used[i][j]=color[i][j]=0;
			}
		}
	}
	void dfs(int x,int y)
	{
		used[x][y]=1;
		color[x][y]=col;
		for(int r=0;r<8;r++)
		{
			int tx=x+dx[r],ty=y+dy[r];
			if(tx<0||ty<0||tx>=h||ty>=w||ma[tx][ty]==0||used[tx][ty])continue;
			dfs(tx,ty);
		}
	}
	void solve()
	{
		col=0;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(used[i][j]||ma[i][j]==0)continue;
				col++;
				dfs(i,j);
			}
		}
		cout<<col<<endl;
	}
};
main()
{
	int a,b;
	while(cin>>a>>b,a)
	{
		E s;s.init(a,b);s.solve();
	}
}

