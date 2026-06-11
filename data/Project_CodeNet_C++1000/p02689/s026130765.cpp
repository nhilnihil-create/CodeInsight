#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,j,y,p=0;
	cin>>n>>m;
	int a[n+1],b[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>j>>y;
		if(a[j]>a[y])
		swap(j,y);
		else if
		(a[j]==a[y])
		b[y]++;
		b[j]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		p++;
	}
	cout<<p;
	return 0;
}