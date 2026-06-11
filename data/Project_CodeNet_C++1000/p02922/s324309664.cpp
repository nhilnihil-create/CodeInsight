#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,d;
	cin>>a>>b;
if(b>a)
	{
		b=b-a;
		--a;
	}
else if(b==1)
{
		cout<<0<<endl;
		return 0;
}
else
{
	cout<<1<<endl;
	return 0;
}
	
	if(b%a!=0)
	{
	d=(b/a)+2;	
	}
	else
	{
		d=(b/a)+1;
	}
	cout<<d<<endl;
	
	
}
