#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	float s=(a[1]+a[2])*1.0/2.0;
	for(int i=3;i<=n;i++)
	{
		s=(s+a[i])*1.0/2.0;
	}
	cout<<s;
 } 