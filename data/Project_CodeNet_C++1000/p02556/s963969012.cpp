#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long int ll;
int a[200006],b[200006],c[200006],n;
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	ios;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int x,y;
		cin>>x>>y;
		a[i]=x+y;
		b[i]=x-y;
		c[i]=y-x;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	sort(c+1,c+1+n);
	int mx=a[n]-a[1];
	mx=max(mx,abs(b[n]+c[n]));
	cout<<mx<<'\n';
}