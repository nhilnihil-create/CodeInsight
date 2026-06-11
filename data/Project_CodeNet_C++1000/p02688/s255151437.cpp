#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,w,x,sum=0;
	cin>>n>>m;
	bool a[n+1];
	for(int i=1;i<=n;i++)
		a[i]=true;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		for(int i=1;i<=x;i++)
		{
			cin>>w;
			a[w]=false;
		}
	}
	for(int i=1;i<=n;i++)
	if(a[i])
		sum++;
	cout<<sum<<endl;
	return 0;
}