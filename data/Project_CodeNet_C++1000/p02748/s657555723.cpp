#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k,minv,xx=1e9+7,yy=1e9+7;
int a[100005],b[100005];

struct node
{
	int x,y,c;
}t[100005];

signed main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)  cin>>a[i],xx=min(xx,a[i]);
	for (int i=1;i<=m;i++)  cin>>b[i],yy=min(yy,b[i]);
	for (int i=1;i<=k;i++)  cin>>t[i].x>>t[i].y>>t[i].c;

	minv=xx+yy;
	
	for (int i=1;i<=k;i++)  minv=min(minv,a[t[i].x]+b[t[i].y]-t[i].c);
	cout<<minv<<endl;
	
	return 0;
}