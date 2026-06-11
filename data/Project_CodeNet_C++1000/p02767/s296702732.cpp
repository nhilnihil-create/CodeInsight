#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i,a[n],d=0;
	double s=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		s=s+a[i];
	}
	s=s/n;
	s=round(s);
	for(i=0;i<n;i++)
	{
		a[i]=a[i]-s;
		d=d+a[i]*a[i];
	}
	cout<<d<<endl;
}