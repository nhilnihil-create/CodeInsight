#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int x,a;
	cin>>x;
	a=x/100;
	a=a*105;
	if(x<=a)
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	
}