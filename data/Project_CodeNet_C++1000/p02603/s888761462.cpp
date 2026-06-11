#include<bits/stdc++.h>
#define fint register int
#define h 5001
#define p 834534
#define int long long
using namespace std;
int a[p];
signed main()
{
	int n;
	cin>>n;
	for(fint i=1;i<=n;i++)
	cin>>a[i];
	int tic=0,mon=1000;
	for(fint i=1;i<=n;i++)
	{
		if(a[i]>a[i-1])
		mon+=a[i]*tic,tic=0;
		if(a[i+1]>a[i])//后一天比这一天价格高，就在这一天狂买
		tic+=(mon/a[i]),mon=mon%a[i];
	}
	cout<<mon;
	return 0;
}