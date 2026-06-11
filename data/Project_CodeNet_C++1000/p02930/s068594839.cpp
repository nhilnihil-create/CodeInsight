#include<bits/stdc++.h>
using namespace std;
#define N 505

int n;
int a[N][N];
inline void dfs(int l,int r,int c)
{
	if(l+1>=r) return;
	int mid=l+r>>1;
	for(int i=l;i<=mid;i++)
	for(int j=mid+1;j<=r;j++)
		a[i][j]=c;
	dfs(l,mid,c+1);
	dfs(mid+1,r,c+1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	dfs(1,n,1);
	for(int i=1;i<=n;i++,cout<<'\n')
	for(int j=i+1;j<=n;j++)
		cout<<a[i][j]+1<<' ';
	
	return 0;
}