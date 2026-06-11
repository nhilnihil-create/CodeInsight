#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n,ok=0;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	sort(b,b+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			ok++;
		}
	}
	if(ok>2)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
	}
	return 0;
}