#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double x,y,X,Y,i,j;
	cin>>x>>y>>X>>Y;
	if(x<X)i=X-x;
	else i=x-X;
	if(y<Y)j=Y-y;
	else j=y-Y;
    printf("%f\n", sqrt((i*i)+(j*j)));
	return 0;
	}
