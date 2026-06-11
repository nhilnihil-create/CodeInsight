#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	long long n;
	cin>>n;
	long long ans=0;
	long long a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			ans+=a[i]*a[j];
		}
	}
	ans/=2;
	cout<<ans<<endl;
}