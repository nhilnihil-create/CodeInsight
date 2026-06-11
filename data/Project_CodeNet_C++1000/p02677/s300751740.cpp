#include<bits/stdc++.h>
using namespace std;

int main()
{
	long double a,b,j,c;
	int h,m;//a是时针10 40
	cin>>a>>b>>h>>m;
	j=30*h-5.5*m;//300 220
	if(j>180)j=360-j;
	//a平方+b平方-2ab*cos
	j=j*3.141592653589793/180;
	c=a*a+b*b-2*a*b*cos(j);
	c=sqrt(c);
	cout<<fixed<<setprecision(20)<<c<<endl;
	return 0;
}