#include<iostream>
#include<algorithm>
using lint=int64_t;
using namespace std;

int N;
int ans[510][510];

void dfs(int l=0,int r=N,int level=1)
{
	if(r-l<2)return;

	int mid=(l+r)/2;
	for(int i=l;i<mid;i++)
	{
		for(int j=mid;j<r;j++)
		{
			ans[i][j]=level;
			ans[j][i]=level;
		}
	}

	dfs(l,mid,level+1);
	dfs(mid,r,level+1);
	return;
}


int main()
{
	cin >> N;

	dfs();
	
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			cout << ans[i][j];
			if(j==N-1)cout << endl;
			else cout << " ";
		}
	}
	return 0;
}

