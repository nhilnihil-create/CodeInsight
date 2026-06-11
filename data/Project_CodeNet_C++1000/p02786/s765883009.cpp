#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
	unsigned long long h,t=0,c=1,c0=1;
	cin>>h;
	
	if(h/2==0)
	{
		cout<<"1";
		return 0;
	}
	
	while(h/2!=0)
	{
		h=h/2;
		//cout<<h<<endl;
		if(c0==1)
		{
			NULL;
		}
		else
		{

			c=c+c0;
		}
		c0=c0*2;
		//cout<<"c="<<c<<endl;
		//cout<<"c0="<<c0<<endl;
		
	}

	t=c0+c;
	cout<<t;
	
	return 0;
}