#include<bits/stdc++.h>
using namespace std;
int main()
{
	int flag;
	int x,y;
	cin>>x>>y;
	if((y-2*x)<0)
	{
		flag=0;
	}
	else if((y-2*x)%2!=0)
	{
		flag=0;
	}
	else
	{
		int b=(y-2*x)/2;
		if(0<=b&&b<=x)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
	}
	if(flag)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
}