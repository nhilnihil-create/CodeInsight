#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,n;
	cin>>k>>n;
	int A[n];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	int d[n];
	for(int i=0;i<n-1;i++)
	{
		d[i]=A[i+1]-A[i];
	}
	d[n-1]=k-A[n-1]+A[0];
	int m=INT_MIN;
	int store=0;
	for(int i=0;i<n;i++)
	{
		m=max(m,d[i]);
		if(m==d[i])
		{
			store=i;
		}
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=d[i];
	}
	sum-=d[store];
	cout<<sum<<endl;
	
}