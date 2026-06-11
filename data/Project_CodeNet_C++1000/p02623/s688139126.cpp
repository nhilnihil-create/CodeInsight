#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<cmath>
#include<map> 
#include<string>
#include<queue>
#include<stack> 
#include<bitset>
#include<list>
#include<set>
#include<utility>
#include<iomanip>
#define IO ios::sync_with_stdio(false)
#define eps 1e-7
#define int long long
using namespace std;
int n,m,k,a[200005],b[200005],suma[200005],sumb[200005],ans=-1;
signed main()
{
	IO;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		suma[i]=suma[i-1]+a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		sumb[i]=sumb[i-1]+b[i];
	}
	for(int i=0;i<=n;i++)
	{
		if(suma[i]>k)break;
		int x=upper_bound(sumb+1,sumb+m+1,k-suma[i])-sumb;
		ans=max(ans,i+x-1);
	}
	cout<<ans;
}