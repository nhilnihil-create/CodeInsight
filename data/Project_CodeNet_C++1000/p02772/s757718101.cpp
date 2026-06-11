#include<iostream>
using namespace std;
int n;
int a[120];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]%2==0)
		{
			if(a[i]%3!=0 && a[i]%5!=0) 
			{
				cout<<"DENIED\n";
				return 0;
			}
		}
	}
	cout<<"APPROVED\n";
	return 0;
}