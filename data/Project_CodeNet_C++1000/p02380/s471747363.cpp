#include<stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	double a, b, c, r, s, l, h, d;
	
	cin >> a >> b >> c;
	
	if(c > 180 && c <= 270) c -= 90;
	if(c > 270) c -= 180;
	
	if(c <= 90){
		r = sin((c / 180) * 3.14159265);
		h = b * r;
		s = a * h / 2;
		d = sqrt(b*b - h*h);
		l = a + b + sqrt(h*h + (a - d)*(a - d));
	}
	else{
		r = sin((c / 180) * 3.14159265);
		h = b * r;
		s = a * h / 2;
		d = sqrt(b*b - h*h);
		l = a + b + sqrt(h*h + (a + d)*(a + d));
	}
	
	printf("%f\n%f\n%f\n",s,l,h);
	
	return 0;
}