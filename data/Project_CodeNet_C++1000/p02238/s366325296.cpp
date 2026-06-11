#include <iostream>
#include <stack>
using namespace std;
static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, time1=0, M[N][N], color[N];
int nt[N], begin[N], end[N];

int next(int r)
{
	int i;
	for(i=nt[r]; i<n; i++)
	{
		nt[r]=i+1;
		if(M[r][i]==0)
			continue;
		if(color[i]==WHITE)
			return i;
	}
	return -1;
	
}

void dfs_visit(int r)
{
	int i, j;
	stack<int> S;
	S.push(r);
	color[r]=GRAY;
	begin[r]=++time1;
	
	while(!S.empty())
	{
		int u=S.top();
		int v=next(u);
		if(v!=-1)
		{
			begin[v]=++time1;
			color[v]=GRAY;
			S.push(v);
		}
		else
		{
			S.pop();
			color[u]=BLACK;
			end[u]=++time1;
		}

	}
}

void dfs()
{
	int i, j;
	for(i=0; i<n; i++)
	{
		color[i]=WHITE;
		nt[i]=0;
	}

	for(i=0; i<n; i++)
	{
		if(color[i]==WHITE)
		{
			dfs_visit(i);
		}
	}
	for(i=0; i<n; i++)
	{
		cout<<i+1<<" "<<begin[i]<<" "<<end[i]<<endl;
	}
}

int main()
{
	int i, j;
	int u, v, k;
	cin>>n;
	for(i=0; i<n; i++)
	{		
		for(j=0; j<n; j++)
		{
			M[i][j]=0;
		}
	}
	
	for(i=0; i<n; i++)
	{
		cin>>v>>k;
		v--;
		for(j=0; j<k; j++)
		{
			cin>>u;
			u--;
			M[v][u]=1;
		}
	}

	dfs();
	return 0;
}
