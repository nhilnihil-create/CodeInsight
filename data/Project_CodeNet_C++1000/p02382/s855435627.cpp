#include <iostream>
#include <string>
#include <stddef.h>
#include <stack>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#define ll long long;

using namespace std;
int n;
int x[100];
int y[100];
int z[100];
int man;
double eu;
double th;
int che;

int manh(int z[]) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += z[i];
	}
	return sum;
}

double euk(int z[]) {
	int ss = 0;
	for (int i = 0; i < n; i++) {
		ss += z[i] * z[i];
	}
	return (double)sqrt(ss);
}

double thr(int z[]) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += z[i] * z[i] * z[i];
	}
	return pow(sum, 1.0 / 3.0);
}

int cheb(int  z[]) {
	int max;
	max = z[0];
	for (int i = 0; i < n; i++) {
		if (max < z[i]) max = z[i];
	}
	return max;
}


int main() {
	

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> y[i];
		z[i] = abs(x[i] - y[i]);
	}

	man = manh(z);
	eu = euk(z);
	che = cheb(z);
	th = thr(z);

	printf("%d\n", man);
	printf("%.8f\n", eu);
	printf("%.8f\n", th);
	printf("%d\n", che);
}