#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	float d;
	cin>>d;
	b=ceil(d/1.08);
	a=b*(1.08);
	c=(b-1)*(1.08);
	if(b<=0)
	{
		cout<<":("<<endl;
	}
	else if(a==d || c==d)
	{
		cout<<b<<endl;
	}
	else
	{
		cout<<":("<<endl;
	}
	
	
}