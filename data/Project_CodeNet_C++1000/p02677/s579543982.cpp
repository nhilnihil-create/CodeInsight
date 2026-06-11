#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=acos(-1);
double a,b,c,d;
double C;
//c^2=a^2+b^2-2abcosC
int main(){
	cin>>a>>b>>c>>d;
	double C=abs(c/12*2*pi+d/60*pi/6-d/60*2*pi);
	//注意10点40时时针不在10上
	printf("%.10lf\n",sqrt(a*a+b*b-2*a*b*cos(C)));
	return 0;
}


