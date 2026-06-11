#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;
 
int main() {
	string str;
	int n;
	cin >> n;
	int x[n], y[n];
	for(int i=0; i<n; i++){
		cin >> x[i];
	}
	for(int i=0; i<n; i++){
		cin >> y[i];
	}
	double d1=0.0,d2=0.0,d3=0.0,dinf=0.0;
	for(int i=0; i<n; i++){
		d1 +=fabs(x[i]-y[i]);
	}
	printf("%.6f\n", d1);
	for(int i=0; i<n; i++){
		d2 += pow(fabs(x[i]-y[i]),2);
	}
	d2 = pow(d2,1.0/2.0);
	printf("%.6f\n", d2);
	for(int i=0; i<n; i++){
		d3 += pow(fabs(x[i]-y[i]),3);
	}
	d3 = pow(d3,1.0/3.0);
	printf("%lf\n", d3);
	for(int i=0; i<n; i++){
		if(dinf < fabs(x[i]-y[i])) dinf = fabs(x[i]-y[i]);
	}
	printf("%lf\n", dinf);
	return 0;
}
