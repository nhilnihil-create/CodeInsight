#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


int main()
{
	int n;
	int x[100000] = {};
	int y[100000] = {};

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> y[i];
	}

	for(int p = 1; p < 4; p++)
	{
		double sum = 0;

		for (int i = 0; i < n; i++)
		{
			sum += pow( (double)abs(x[i] - y[i]), (double)p);
		}

		sum = pow(sum, 1.0 / (double)p);

		cout << setprecision(20) << sum << endl;
	}

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		int result = abs(x[i] - y[i]);

		if(result > max)
		{
			max = result;
		}
	}

	cout << setprecision(20) << max << endl;
}
