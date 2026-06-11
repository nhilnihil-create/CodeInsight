#include<iostream>
using namespace std;
int main()
{
	char a[1001];
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='A'&&a[i+1]=='B'&&a[i+2]=='C')
		{
			sum++;
		}
	}
	cout<<sum;
}