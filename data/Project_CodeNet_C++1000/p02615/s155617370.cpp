#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<map>
#define ll long long
#define MM(arr,x) memset(arr,x,sizeof(arr))
#define INF 10000000
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	cin>>n;
	int a[n+10];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ll ans=0;
	int t=n;
	for(int i=1;i<=n;i++)
	{
		if(t>1)
		{
			ans+=a[i];
			t--;
		}
		if(t>1&&i>1)
		{
			ans+=a[i];
			t--;
		}
	}
	cout<<ans;
	return 0;
}