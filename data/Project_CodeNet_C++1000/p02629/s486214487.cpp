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
int f[1000006],k,n,pos;
char ans[1000006];
int kuai(int x,int y)
{
	int anss=1;
	while(y)
	{
		if(y%2)
		{
			anss=anss*x;
		}
		y/=2;
		x=x*x;
	}
	return anss;
}
signed main()
{
	IO;
	cin>>n;
	while(n)
	{
		k=n%26;
		if(k==0)k=26;
		n-=k;
		ans[++pos]='a'+k-1;
		n/=26;
	}
	for(int i=pos;i>=1;i--)
	{
		cout<<ans[i];
	}
}