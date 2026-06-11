#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll h,w,ans=0;
	cin>>h>>w;
	char val[h+3][w+3];
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			cin>>val[i][j];
	ll l[h+3][w+3]{};
	ll r[h+3][w+3]{};
	ll u[h+3][w+3]{};
	ll d[h+3][w+3]{};
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			if(val[i][j]=='.')
				l[i][j]=l[i][j-1]+1;
	for(int i=1;i<=h;i++)
		for(int j=w;j>=1;j--)
			if(val[i][j]=='.')
				r[i][j]=r[i][j+1]+1;
	for(int j=1;j<=w;j++)
		for(int i=1;i<=h;i++)
			if(val[i][j]=='.')
				d[i][j]=d[i-1][j]+1;
	for(int j=w;j>=1;j--)
		for(int i=h;i>=1;i--)
			if(val[i][j]=='.')
				u[i][j]=u[i+1][j]+1;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			if(val[i][j]=='.')
				ans=max(ans,l[i][j]+r[i][j]+u[i][j]+d[i][j]-3);
	cout<<ans;
	return 0;
}
