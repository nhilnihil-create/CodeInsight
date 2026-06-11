#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int mtr[2001][2001];
	int n,x,y;
	cin>>n>>x>>y;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		 mtr[i][j]=abs(i-j);
	}
	mtr[x][y]=1;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i==j)
			 continue;
			else if(i<j)
			{
				mtr[i][j]=min(mtr[i][j],mtr[i][x]+mtr[j][y]+1);
			}
			else
			{
				mtr[i][j]=min(mtr[i][j],mtr[i][y]+mtr[j][x]+1);
			}
		}
	}
	int memo[2001];
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
	    {
	    	memo[mtr[i][j]]++;
		}
	}
	for(int i=1; i<=n-1; i++)
	{
		cout<<memo[i]/2<<"\n";
	}
	return 0;
}