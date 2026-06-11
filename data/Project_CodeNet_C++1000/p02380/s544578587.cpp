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

int main()
{
    double l,d,k,s,c,h,p,q;
	while(cin>>l>>d>>k)
	{
		k=(k/180)*PI;
		s=l*d*sin(k)/2;
		q=l*l+d*d-2*d*l*cos(k); 
		p=sqrt(q);
		c=l+d+p;
		h=(2*s)/l;
		cout<<setiosflags(ios::fixed)<<setprecision(8);
		cout<<s<<" "<<c<<" "<<h;
	
	
	
	
	}
	
		




}