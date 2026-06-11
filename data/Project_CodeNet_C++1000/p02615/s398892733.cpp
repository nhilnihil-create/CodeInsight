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
#define IO ios::sync_with_stdio(false)
#define int long long
using namespace std;
int n,a[200005],pos=1,ans;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	IO;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	/*for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	ans+=a[pos];
	//cout<<ans<<endl;
	//pos++;
	for(int i=3;i<=n;i++)
	{
		if(i%2!=0)pos++;
		ans+=a[pos];
	}
	cout<<ans;
}
