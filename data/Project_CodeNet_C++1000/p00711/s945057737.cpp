#include <bits/stdc++.h>

using namespace std;

class P
{
public:
	int x,y;
	P(int X,int Y)
	{
		x=X;
		y=Y;
	}
};

int main()
{
	stack<P>st;
	int n,m;
	int numX[4]={0,1,0,-1};
	int numY[4]={1,0,-1,0};

	while(cin>>n>>m && n)
	{
		int flag[500][500]={};
		int count=0;
		string in;
		char set[500][500]={};

		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin >> set[i][j];
			}
		}

		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(set[i][j]=='@')
				{
					st.push(P(j,i));
					flag[i][j]=1;
				}
			}
		}

		int xx,yy;

		while(!st.empty())
		{
			count++;
			xx=st.top().x;
			yy=st.top().y;
			st.pop();
			for(int i=0;i<4;i++)
			{
				if(set[numY[i]+yy][numX[i]+xx]=='.' && flag[numY[i]+yy][numX[i]+xx]==0)
				{
					st.push(P(numX[i]+xx,numY[i]+yy));
					flag[numY[i]+yy][numX[i]+xx]=1;
				}
			}

		}
		cout << count << endl;
	}

    return 0;
}