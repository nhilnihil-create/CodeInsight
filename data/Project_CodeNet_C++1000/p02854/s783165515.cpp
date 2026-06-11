#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,l=0,r=0,d;
	cin>>n;
	long long i,j,a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		l+=a[i];
	}
	for(i=n-1;i>=0;i--)
	{
		l-=a[i];
		r+=a[i];
		if(i==n-1 || abs(l-r)<d) d=abs(l-r);
	}
cout<<d;
}