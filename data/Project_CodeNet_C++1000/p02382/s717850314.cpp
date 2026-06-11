#include<stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	int n;
	double x[1000], y[1000], z[1000];
	double a = 0, b = 0, c = 0, d = 0;
	
	cin >> n;
	
	for(int i = 0; i < n; ++i){
		cin >> x[i];
	}
		for(int i = 0; i < n; ++i){
		cin >> y[i];
	}
	
	for(int i = 0; i < n; ++i){
		
		a += fabs(x[i] - y[i]);
		b += (x[i] - y[i]) * (x[i] - y[i]);
		c += fabs( (x[i] - y[i]) * (x[i] - y[i]) * (x[i] - y[i]) );
		z[i] = fabs(x[i] - y[i]);
	}
	
	for(int i = 0; i < n-1; ++i){
		if(z[i] > z[i+1]){
			z[i+1] = z[i];
		}
	}
	
	b = sqrt(b);
	c = cbrt(c);
	d = z[n-1];
	
	
	printf("%f\n%f\n%f\n%f\n",a,b,c,d);
	
	return 0;
}