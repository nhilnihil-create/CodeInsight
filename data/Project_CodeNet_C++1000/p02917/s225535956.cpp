#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+1],b[n];
	for(int i=1;i<n;i++)
	cin>>b[i];
	a[1]=b[1];
	a[2]=b[1];
	for(int i=2;i<n;i++)
	{
		if(a[i]>b[i])
		a[i]=b[i];
		a[i+1]=b[i];
	}
	long long s=0;
	for(int i=1;i<=n;i++)
	{
		s+=a[i];
	}
	cout<<s;
 } 