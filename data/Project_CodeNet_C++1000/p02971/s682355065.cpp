#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
int main()
{
	long long int i,n,j,p,r,max=0;
	
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
		for(i=0;i<n;i++)
			{
				if(max<a[i])
				{
					max=a[i];
					p=i;
				}
					
			}
	sort(a,a+n);
	r=a[n-2];
	for(i=0;i<n;i++)
		{
			if(i!=p)
				cout<<max<<endl;
			else
				cout<<r<<endl;
		}
}
