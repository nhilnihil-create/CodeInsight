#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

const int N = 3;

double minkowsky_distance(double[], double[], int, int);


int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;

	double x[n], y[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> y[i];
	}

	printf("%9.8f\n", minkowsky_distance(x, y, n, 1));
	printf("%9.8f\n", minkowsky_distance(x, y, n, 2));
	printf("%9.8f\n", minkowsky_distance(x, y, n, 3));
	printf("%9.8f\n", minkowsky_distance(x, y, n, -1));

	return 0;
}

// p = -1 == ∞ とする
double minkowsky_distance(double x[], double y[], int n, int p)
{
	double d = 0;
	switch(p)
	{
		case 1:
		{
			for (int i = 0; i < n; ++i)
			{
				d += fabs(x[i] - y[i]);
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i < n; ++i)
			{
				d += pow(x[i] - y[i], 2.0);
			}
			d = sqrt(d);
			break;
		}
		case 3:
		{
			for (int i = 0; i < n; ++i)
			{
				d += pow(fabs(x[i] - y[i]), 3.0);
			}
			d = cbrt(d);
			break;
		}
		case -1:
		{
			double max = 0;
			for (int i = 0; i < n; ++i)
			{
				d = fabs(x[i] - y[i]);
				if (max < d) max = d;
			}
			d = max;
			break;
		}
		default:
		{
			break;
		}
	}
	return d;
}