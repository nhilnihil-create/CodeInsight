#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define Check system("pause")
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int w[100005],d[100005];

int main()
{
	ios::sync_with_stdio(false);
	int a,b,m,ans=0,l,r,x,y,c,k;
	cin>>a>>b>>m;
	l=r=1e9;
	for(int i=1;i<=a;i++)
	{
		cin>>w[i];
		l=min(l,w[i]);
	}
	for(int i=1;i<=b;i++)
	{
		cin>>d[i];
		r=min(r,d[i]);
	}
	ans=l+r;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>c;
		k=w[x]+d[y]-c;
		ans=min(ans,k);
	}
	cout<<ans;
	return 0;
}


