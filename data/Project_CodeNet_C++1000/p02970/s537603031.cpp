#include<iostream>
using namespace std;
int main()
{
	int a,b; cin>>a>>b;
	float c=(a-b-1)*(1.0)/(b*2+1);
	c*=100;
	int d=c;
	d%100 < 50 ?cout<<d/100 + 1:cout<<d/100 + 2;
}
