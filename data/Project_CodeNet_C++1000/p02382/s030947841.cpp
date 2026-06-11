#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	double x[1000];
	double y[1000];
	//int i2;
	int i3;
	double D1 = 0;
	double D2 = 0;
	double D3 = 0;
	double D4 = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		cin >> y[i];
	}

	for (int i1 = 0; i1 < n; i1++)
	{
		if (0 <= x[i1]-y[i1])
		{
			D1 = D1 + x[i1] - y[i1];
		}
		else
		{
			D1 = D1 - (x[i1] - y[i1]);
		}
	}

	for (int i2 = 0; i2 < n; i2++)
	{
		D2 = D2 + ((x[i2] - y[i2])*(x[i2] - y[i2]));
	}

	D2 = sqrt(D2);

	for (i3 = 0; i3 < n; i3++)
	{
		if (0 <= x[i3] - y[i3])
		{
			D3 = D3 + ((x[i3] - y[i3])*(x[i3] - y[i3])*(x[i3] - y[i3]));
		}
		else 
		{
			D3 = D3 - ((x[i3] - y[i3])*(x[i3] - y[i3])*(x[i3] - y[i3]));
		}
	}

	D3 = pow(D3,1.0/3.0);


	if (0 <= x[0] - y[0])
	{
		D4 = x[0] - y[0];
	}
	else
	{
		D4 = -(x[0] - y[0]);
	}
	

	for (int i4 = 1; i4 < n; i4++)
	{
		if (D4 < x[i4] - y[i4])
		{
			D4 = x[i4] - y[i4];
		}
		else if (D4< -(x[i4] - y[i4]))
		{
			D4 = -(x[i4] - y[i4]);
		}
	}

	cout << fixed << std::setprecision(6) << D1 << endl;
	cout << fixed << std::setprecision(6) << D2 << endl;
	cout << fixed << std::setprecision(6) << D3 << endl;
	cout << fixed << std::setprecision(6) << D4 << endl;

	return 0;
}