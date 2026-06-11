#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int k;
	cin>>n>>k;
	int a[n];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum=sum+a[i];
	}
	double c= ((double)1/(4*k))*sum;
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=c)
		count++;
	}
	if(count>=k)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	
}