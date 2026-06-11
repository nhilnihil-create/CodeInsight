#include <bits/stdc++.h>
using namespace std;
double angle(int h,int m);
int main()
{
	int a,b,h,m;
	cin>>a>>b>>h>>m;
long double ang,dis;
	ang=angle(h,m);
	if(ang>180)
	{
		ang=(360-ang);
	}
	ang=(3.141592653589793238462643383279/180)*ang;

	dis=(a*a)+(b*b)-((2*a*b)*cos(ang));
	dis=sqrt(dis);
	cout<<fixed<<setprecision(20)<<dis;
	
	
}


double angle(int h,int m)
{
	double a,b,c,d;
	a=h*30;
	b=m*6;
	c=30*(b/360);
	if(a>=b)
	{
		d=a+c-b;
	}
	else
	{
		d=b-(a+c);
	}
	return d;
}