#include<iostream>
#include<cstdio>
using namespace std;
int a[1000001];
int main()
{
	int i,n,f=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]%2==0)
		{
			if(a[i]%3==0||a[i]%5==0);
			else
				f=1;
		}	
	}
	if(f==1)
		cout<<"DENIED";
	else
		cout<<"APPROVED";
	return 0;
}