#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i,a[n],b[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	for(i=0;i<n;i++)
	{
		if(a[i]==b[n-1])
		{
			cout<<b[n-2]<<endl;
			continue;
		}
		cout<<b[n-1]<<endl;
	}
}