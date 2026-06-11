#include<iostream>
using namespace std;
main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a>=b)
	{
		int t=a-b;
		int k=c-t;
		if(k>=0)
		{
			cout<<k<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
}
