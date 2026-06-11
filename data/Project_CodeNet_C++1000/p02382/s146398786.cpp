#include <iostream>
#include <cmath>
#include <iomanip>

int main(void)
{
	using namespace std;
	int n;
	double D1, D2, D3, D4 = 0;
	cin >> n;
	int x[n], y[n], d[n];
	for(int i = 0; i < n; i++)
		cin >> x[i];
	for(int i = 0; i < n; i++)
		cin >> y[i];
	for(int i = 0; i < n; i++)
		d[i] = abs(x[i] - y[i]);
	for(int i = 0; i < n; i++)
		D1 += d[i];
	for(int i = 0; i < n; i++)
		D2 += d[i] * d[i];
	for(int i = 0; i < n; i++)
		D3 += d[i] * d[i] * d[i];
	for(int i = 0; i < n; i++)
	{
		if(D4 < d[i])
			D4 = d[i];
	}
	cout << fixed << setprecision(8) << D1 << endl << sqrt(D2) << endl << pow(D3, 1.0 / 3) << endl << D4 << endl;
}
