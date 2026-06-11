#include<bits/stdc++.h>
using namespace std;
	
int main()
{
	int n,k,m=0;//n人，k样东西
	cin>>n>>k; 
	int a[k+1],b[n+1],x;
	for(int i=1;i<=n;i++)
	b[i]=0;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		for(int p=1;p<=a[i];p++)
		{
			cin>>x;
			b[x]++;
		}
	}
	for(int i=1;i<=n;i++)
	if(b[i]==0)
	m++;
	cout<<m;
	return 0;
}