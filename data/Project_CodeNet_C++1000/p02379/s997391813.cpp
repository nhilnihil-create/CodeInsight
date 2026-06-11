#include<stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	long double Ax, Ay, Bx, By;
	long double a;
	
	
	cin >> Ax >> Ay >> Bx >> By;
	
	a = (Bx - Ax) * (Bx - Ax) + (By - Ay) * (By - Ay);
	
	printf("%lf\n",sqrt(a)) ;
	
	return 0;
}