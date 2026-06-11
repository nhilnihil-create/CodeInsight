#include<bits/stdc++.h>
using namespace std;
#define pi 3.141592653589793238
int main()
{
	int a,b,n,k;
	cin>>a>>b>>n>>k;
	double f=k*6;
	double h=n*30+k/2.0;
	double  m=1.0*(f-h)*pi/180;
	double ans=a*a+b*b-2*a*b*cos(m);
	printf("%.20f\n",sqrt(ans));
 } 
