#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,n,i;
	cin>>k>>n;
	int a[n+2];
	a[n+1]=k;
	a[0]=0;
	for(i=1;i<n+1;i++)
	cin>>a[i];
	int mx=0;
	mx=a[1]-a[0]+a[n+1]-a[n];
	for(i=1;i<n;i++)
	{
		
		mx=max(mx,a[i+1]-a[i]);
	}
cout<<(k-mx);
}
