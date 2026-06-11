#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long a,c,product;
	double b;
	cin>>a>>b;
	
	b=b+1e-7;
	c=b*100;
	product=(a*c)/100;
	cout<<product;
	
	return 0;
}