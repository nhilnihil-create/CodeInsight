#include"bits/stdc++.h"

using namespace std;

#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl "\n"
#define sp " "
#define int long long
#define PI 3.141592653589793
#define scanstr(s) cin>>ws; getline(cin,s);

void solve()
{
	int grid[3][3],x,y,z;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>grid[i][j];
		}
	}
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<3;i++)
	{
		x=grid[i][0], y= grid[i][1], z=grid[i][2];
		if(binary_search(a,a+n,x)&&binary_search(a,a+n,y)&&binary_search(a,a+n,z))
		{
			cout<<"Yes\n";
			return ;
		}
	}
	for(int i=0;i<3;i++)
	{
		x=grid[0][i], y= grid[1][i], z=grid[2][i];
		if(binary_search(a,a+n,x)&&binary_search(a,a+n,y)&&binary_search(a,a+n,z))
		{
			cout<<"Yes\n";
			return ;
		}
	}
	x=grid[0][0], y=grid[1][1], z=grid[2][2];
	if(binary_search(a,a+n,x)&&binary_search(a,a+n,y)&&binary_search(a,a+n,z))
	{
		cout<<"Yes\n";
		return ;
	}
	x=grid[0][2], y=grid[1][1], z=grid[2][0];
	if(binary_search(a,a+n,x)&&binary_search(a,a+n,y)&&binary_search(a,a+n,z))
	{
		cout<<"Yes\n";
		return ;
	}
	cout<<"No\n";
	return ;
}

int32_t main()
{
	FastIO;
	solve();
	return 0;
}
