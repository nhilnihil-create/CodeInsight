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
int p[1005],k,n,ans;
signed main()
{
	IO;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=k;i++)
	{
		ans+=p[i];
	}
	cout<<ans;
}