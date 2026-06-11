#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
	int a;
	double p1 = 0, p2 = 0, p3 = 0, pi = 0;
	cin >> a;
	int x[a], y[a];
	for (int i = 0; i < a; i++) {
	    cin >> x[i];
	}
	for (int i = 0; i < a; i++) {
	    cin >> y[i];
	}
	for (int i = 0; i < a; i++) {
	    p1 += abs(x[i] - y[i]);
	    p2 += abs(x[i] - y[i]) * abs(x[i] - y[i]);
	    p3 += abs(x[i] - y[i]) * abs(x[i] - y[i]) * abs(x[i] - y[i]);
	    if (abs(x[i] - y[i]) > pi) {
	        pi = abs(x[i] - y[i]);
	    }
	}
	p2 = sqrt(p2);
	p3 = pow(p3, 1.0 / 3.0);
	printf("%.6f\n%.6f\n%.6f\n%.6f\n", p1, p2, p3, pi);
}
