#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	printf("%lf\n",a*b*sin(c/180.0*M_PI)/2.0);
	printf("%lf\n",a+b+sqrt(a*a+b*b-2.0*a*b*cos(c*M_PI/180.0)));
	printf("%lf\n",b*sin(c*M_PI/180.0));
	return 0;
}