#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int n,a[101];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]%2==0)
		{
			if(a[i]%3!=0&&a[i]%5!=0) 
			{
				cout<<"DENIED";
				return 0;
			}
		}
	}
	cout<<"APPROVED";
	return 0;
}