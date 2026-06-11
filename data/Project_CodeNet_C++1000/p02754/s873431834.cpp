#include  <bits/stdc++.h>
using namespace std;
int main()
{
	long int x,c,d,n,a,b;
	cin>>n>>a>>b;
	c=n%(a+b);
	x=n/(a+b);
	if(c>a)
	{
	d=(x*a)+a;
	}
	else
	{
		d=(x*a)+c;
	}
	cout<<d<<endl;
}