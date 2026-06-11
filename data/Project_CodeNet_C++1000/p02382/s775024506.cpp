#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<stdio.h>
#include<cctype>
#include<algorithm>
#include<string.h>
#include<iomanip>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148
using namespace std;
#define A 0.33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333


int main()
{
	double x[105],y[105],m=-1,a[105];
	int n;
	double b=0,c=0,d=0;
	while(cin>>n){

		for(int i=0;i<n;i++)
			cin>>x[i];
		for(int i=0;i<n;i++)
			cin>>y[i];
	//?????\??????
	for(int i=0;i<n;i++)
		{
			a[i]=abs(x[i]-y[i]);
			b+=a[i];
			c+=a[i]*a[i];
			d+=a[i]*a[i]*a[i];
	}
	    for(int i=0;i<n;i++)
		{
	
         m=max(m,a[i]);
		}
		cout<<setiosflags(ios::fixed)<<setprecision(10);
		cout<<b<<endl;
		cout<<sqrt(c)<<endl;
		cout<<pow(d,A)<<endl;
		cout<<m<<endl;


		
		

	}
}