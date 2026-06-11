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
int fa[10000007],ans,n;
signed main()
{
	cin>>n;
	for(int i=1;i*i<=n;i++)
	{
		for(int j=i;i*j<=n;j++)
		{
			fa[i*j]+=2;
			if(i==j)fa[i*j]--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans+=i*fa[i];
	}
	cout<<ans;
}