#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b;
	double x,y,z;
	x=(a*100.0)/8;
	y=b*10;
	z=ceil(x);
	c=(z*0.08);
	d=(z*0.1);
	
	if(c==a && d==b)
	{
		cout<<z<<endl;
		return 0;
	}
	z=ceil(y);
	c=(z*0.08);
	d=(z*0.1);
	if(c==a && d==b)
	{
		cout<<z<<endl;
		return 0;
	}

	cout<<-1<<endl;
	
}