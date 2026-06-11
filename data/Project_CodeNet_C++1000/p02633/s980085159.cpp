#include<bits/stdc++.h>
using namespace std;

int lcm(int a, int b)
{
	int r, a1=a, b1=b;
	while(b>0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return (a1*b1)/a;
}

int main()
{
	int x, l;
	
	cin>>x;
	
	if(360%x==0)
	cout<<360/x;
	
	else
	{
		l=lcm(360, x);
		cout<<l/x;
	}
}
