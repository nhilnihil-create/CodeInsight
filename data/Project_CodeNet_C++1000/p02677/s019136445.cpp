#include <iostream>
#include <algorithm>
#include<set>
#include<math.h>
#include<iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
#define _USE_MATH_DEFINES

int main() {
	long double a,b,h,m,x,y,z,f;
	cin>>a>>b>>h>>m;
	x=30*h+m/2;
	y=6*m;
	if(x<y)
	{
		z=y-x;
	}
	else{
		z=x-y;
	}
    if(z>180)
    {
    	z=360-z;
	}
	z*=3.141592653589/180;

	f=sqrt(a*a+b*b-2*a*b*cos(z));


    cout << setprecision(10)<< f << "\n";	
	return 0;
}