#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,m,a[1005],sum,cnt;
double x;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];
	sum+=a[i];
	}
	x=sum*1.0/(4*m);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x) cnt++;
	}
	if(cnt>=m) cout<<"Yes";
	else cout<<"No";
return 0;
}
