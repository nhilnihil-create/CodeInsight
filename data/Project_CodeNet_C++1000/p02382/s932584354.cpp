#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int n;
double x[100], y[100];

double dist (double p)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += pow(abs(x[i] -y[i]), p);
	}
	return pow (sum, 1.0/p);
}



int main(int argc, char const *argv[])
{
	cout <<fixed << setprecision(12);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> y[i];
	}

	cout << dist(1) << endl;
	cout << dist(2) << endl;
	cout << dist(3) << endl;

	double m = 0;

	for (int i = 0; i < n; ++i)
	{
		m = max(m, abs(x[i]-y[i]));
	}
	cout << m <<endl;




	return 0;
}
