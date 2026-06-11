#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define ref goto refrain
int main(){
	double x1,x2,y1,y2;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	printf("%lf\n",a);
	return 0;
}