#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
	double r;
	double p=3.141592653589;
	scanf("%lf", &r);
	//printf("%f %f\n",r*r*p,p);
	double x=r*r*p;double y=2.0*r*p;
	printf("%f %f\n",x,y); 
return 0;
}