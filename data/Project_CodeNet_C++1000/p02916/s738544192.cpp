#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
{
	int n,i,s=0;
	cin>>n;
	int a[n],b[n],c[n-1];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	for(i=0;i<n-1;i++)
		cin>>c[i];
	for(i=0;i<n;i++)
	{
		s=s+b[a[i]-1];
		if(a[i+1]-a[i]==1)
			s=s+c[a[i]-1];
	}
	cout<<s<<endl;
}