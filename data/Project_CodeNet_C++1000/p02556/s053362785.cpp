#include<bits/stdc++.h>

using namespace std;

const int N=1e5+1;

int n,x[2*N],y[2*N],a[2*N],b[2*N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d", x+i,y+i);
		a[i]=x[i]+y[i];
		b[i]=x[i]-y[i];
	} 
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	cout<<max(a[n]-a[1],b[n]-b[1])<<endl;
	return 0;
}