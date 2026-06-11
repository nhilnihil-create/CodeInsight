#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>

using namespace std;

int main() {
	int n, x[100] = { 0 }, y[100] = { 0 }, i;
	double Dinf = 0, D1 = 0, D2 = 0, D3 = 0;
	cin >> n;
	for (i = 0; i<n; i++){
		cin >> x[i];
	}
	for (i = 0; i<n; i++){
		cin >> y[i];
	}
	for (i = 0; i<n; i++) {
		D1 += abs(x[i] - y[i]);
		D2 += pow(x[i] - y[i], 2);
		D3 += pow(abs(x[i] - y[i]), 3);
		Dinf = max((double)abs(x[i] - y[i]), Dinf);
	}
	printf("%.8f %.8f %.8f %.8f\n", D1, sqrt(D2), cbrt(D3), Dinf);
}