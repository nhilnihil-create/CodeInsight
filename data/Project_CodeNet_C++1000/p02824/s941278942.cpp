#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
ll n,m,v,p,a[N],ans,d;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	cin>>n>>m>>v>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=p;
	for(ll i=p+1;i<=n&&a[i]+m>=a[p];i++)
	{
		if(n-(i-p)>=v) ans++;
		else if( ((v+(i-p)-n)*m-d-1) / (i-p) +1+a[p] <=a[i]+m ) ans++;
		d+=a[p]-a[i];
	}
	cout<<ans<<endl;
	return 0;
}
/* 10 4 8 5
7 6 6 6 5 5 4 3 2 1
*/