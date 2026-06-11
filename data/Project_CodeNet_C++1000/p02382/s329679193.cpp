#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void Input(int *X, int *Y, int n)
{
	for (int i = 0; i < n; i++) {
		cin >> X[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> Y[i];
	}
}

//ミンコフスキー距離
double Minkowski(int *X, int *Y, int n, int p)
{
	double total = 0;

	for (int i = 0; i < n; i++) {
		total += pow(abs(X[i] - Y[i]), p);
	}
	
	total = pow(total, (double)1 / p);

	return total;
}

//チェビチェフ距離
double ChebyshevDistance(int *X, int *Y, int n)
{
	double max = 0;

	for (int i = 0; i < n; i++) {
		if (max < abs(X[i] - Y[i])) {
			max = abs(X[i] - Y[i]);
		}
	}

	return max;
}

int main()
{
	int n, X[100], Y[100];
	cin >> n;

	Input(X, Y, n);

	for (int i = 1; i <= 3; i++) {
		cout << fixed <<setprecision(6) << Minkowski(X, Y, n, i) << endl;
	}

	cout << fixed << setprecision(6) << ChebyshevDistance(X, Y, n) << endl;

	return 0;
}
