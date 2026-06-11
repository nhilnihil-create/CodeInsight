#include<iostream>
using namespace std;
int main()
{
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	long long x,y,z,s;
	x=a*c;
	y=a*d;
	z=b*c;
	s=b*d;
	if(x>y && x>z && x>s)
	{
		cout<<x;
	}
	else if(y>z && y>s )
	{
		cout<<y;
	}
	else if(z>s)
	{
	     cout<<z;
		 	
	}
	else
	{
		cout<<s;
	}
	
	return 0;
}