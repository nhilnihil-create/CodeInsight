#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,j;
	cin>>n;
	int a[n+1],b[n+1],c[n];
	for(i=1;i<n+1;i++)
		cin>>a[i];
	for(i=1;i<n+1;i++)
		cin>>b[i];
	for(i=1;i<n;i++)
		cin>>c[i];
	int ans=0;
	for(i=1;i<n+1;i++)
	{
		j=a[i];
		ans+=b[j];
		if(i-1>=0 && a[i-1]+1==a[i])
			ans+=c[j-1];
	}
	cout<<ans;
	return 0;
}