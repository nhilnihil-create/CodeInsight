#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int i;
	int a[6];
	int b;
	for(i=1;i<=5;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		b=i;
	}
	cout<<b;
	
	return 0;
}