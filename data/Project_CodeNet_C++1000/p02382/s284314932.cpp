#include <iostream>
#include <cstring>
#include <sstream>
#include <cctype>
#include <cmath>
#include <cstdio>
using namespace std;
#define MPI  3.14159265358979323846


int main(){

	int n;
	cin >> n;

	int x[101], y[101];
	for (int i = 0; i < n; i++){
		cin >> x[i];
	}
	for (int i = 0; i < n; i++){
		cin >> y[i];
	}

	double l1=0, l2=0, l3=0, li;
	li = abs(x[0] - y[0]);
	for (int i = 0; i < n; i++){
		l1 += abs(x[i] - y[i]);
		l2 += pow(x[i] - y[i], 2);
		l3 += pow(abs(x[i] - y[i]), 3);
		if (li < abs(x[i] - y[i]))li = abs(x[i] - y[i]);
	}

	printf("%.6f\n%.6f\n%.6f\n%.6f\n", l1, sqrt(l2), pow(l3,0.333333333333), li);

	return 0;
}
