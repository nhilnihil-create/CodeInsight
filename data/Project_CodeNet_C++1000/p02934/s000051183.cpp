#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
{
	double b=0,c;
	int n;
	cin>>n;
	int a[n],i;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		{
			b=b+(float)(1)/(float)(a[i]);
		}
	c=1/b;
	cout<<c<<endl;	
}