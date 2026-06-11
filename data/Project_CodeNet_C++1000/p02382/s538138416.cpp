#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

double calcDistance(const int x[], const int y[], int n, int p);
double calcChebyshevDistance(const int x[], const int y[], int n);

int main(void)
{	
	int n, x[100], y[100];
	cin >> n;	
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> y[i];
	
	cout << fixed << calcDistance(x, y, n, 1) << endl;
	cout << calcDistance(x, y, n, 2) << endl;
	cout << calcDistance(x, y, n, 3) << endl;
	cout << calcChebyshevDistance(x, y, n) << endl;
	
	return 0;
}

double calcDistance(const int x[], const int y[], int n, int p)
{
	long int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pow(fabs(x[i] - y[i]), p);
	}
	
	return pow(sum, 1.0 / p);
}

double calcChebyshevDistance(const int x[], const int y[], int n)
{
	int max = 0;
	for (int i = 0; i < n; i++) {
		int d = fabs(x[i] - y[i]);
		if (d > max) max = d;
	}
	
	return max;
}