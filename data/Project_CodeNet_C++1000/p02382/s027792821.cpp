#include<iostream>
#include<cmath>
#include<stdio.h>
#include<iomanip>
using namespace std;
int main(){
	int n, x[1000], y[1000];
	double p1 = 0, p2 = 0, p3 = 0, pinf = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i];
	}
	for (int i = 0; i < n; i++){
		cin >> y[i];
	}
	for (int i = 0; i < n; i++){
		p1 += abs(x[i] - y[i]);
		p2 += pow(abs(x[i] - y[i]), 2);
		p3 += pow(abs(x[i] - y[i]), 3);
		pinf = fmax(pinf, abs(x[i] - y[i]));
	}
	p2 = sqrt(p2);
	p3 = pow(p3, 1.0 / 3);
	cout <<fixed<<setprecision(6)<< p1 << endl << p2 << endl << p3 << endl << pinf << endl;

}

