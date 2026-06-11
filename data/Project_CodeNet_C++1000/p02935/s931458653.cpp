#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n;
	cin>>n;
	long double b;
	long int i,a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	sort(a,a+n);
	b=(a[0]+a[1])/2.00000;
	for(i=2;i<n;i++)
	{
		b=(b+a[i])/2;
	}
	cout<<b;
}