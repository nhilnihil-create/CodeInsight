#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
void minc(int x[],int y[],int n,int p);
void mincInf(int x[], int y[], int n);

int main() {
	int n,x[110],y[110];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}

	//p = 1,2,3
	minc(x, y, n, 1);
	minc(x, y, n, 2);
	minc(x, y, n, 3);
	
	//p is infinite
	mincInf(x, y, n);
	
	return 0;
}

void minc(int x[],int y[],int n,int p) {
	double d = 0.0;

	for (int i = 0; i < n; i++) {
		double z = abs(x[i] - y[i]);
		d += pow(z, p);
	}
	d = pow(d, 1.0 / p);
	cout << fixed << setprecision(6) << d << endl;
}

void mincInf(int x[], int y[], int n) {
	double max = 0;

	for (int i = 0; i < n; i++) {
		double z = abs(x[i] - y[i]);
		if (z > max) max = z;
	}
	cout << fixed << setprecision(6) << max << endl;
}