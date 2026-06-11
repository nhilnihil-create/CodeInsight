#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<stdio.h>
#include<cctype>
#include<algorithm>
#include<string.h>
#include<iomanip>

using namespace std;

int main()
{
	double x_1,y_1,x_2,y_2;
	double a,b,c;
	while(cin>>x_1>>y_1>>x_2>>y_2)
	{
		a=x_1-x_2;
		b=y_1-y_2;
		c=a*a+b*b;
		cout<<setiosflags(ios::fixed)<<setprecision(8);
		cout<<sqrt(c);


	
	
	
	}







}