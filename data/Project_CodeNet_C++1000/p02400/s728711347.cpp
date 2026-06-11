#include <iostream>
#include <stdio.h>
using namespace std;
 
int main(){
	double r,are,circ,p;
	cin >> r;
	p=3.141592653589;
	
	are=2*p*r;
	circ=r*r*p;
	printf("%f %f\n",circ,are);
    return 0;
}