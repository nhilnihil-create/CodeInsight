#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n,b,k;
	cin>>n;
	long int i,a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	
	sort(a,a+n);
	b=n/2;
	k=a[b]-a[b-1];
	
	cout<<k;
}