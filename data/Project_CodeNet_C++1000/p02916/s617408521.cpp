#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+1],b[n+1],c[n];
	a[0]=0;
	c[0]=0;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	cin>>b[i];
	for(int i=1;i<n;i++)
	cin>>c[i];
	long long s=0;
	s+=b[a[1]];
	for(int i=2;i<=n;i++)
	{
		s+=b[a[i]];
		if(a[i]==(a[i-1]+1))
		s+=c[a[i-1]];
	}
	cout<<s;
 } 