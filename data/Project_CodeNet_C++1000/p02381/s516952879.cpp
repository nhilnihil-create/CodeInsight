#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n, s[1000] = { 0 }, sum = 0;
	double ave = 0.0, sigma = 0.0, standard_deviation = 0.0;
	while (true)
	{
		cin >> n;
		if (n == 0) break;
		sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			sum += s[i];
		}
		ave = (double)sum / n;
		sigma = 0.0;
		for (int i = 0; i < n; i++) {
			double temp = s[i] - ave;
			sigma += temp * temp;
		}
		standard_deviation = sqrt(sigma / n);
		cout << fixed
			<< setprecision(8)
			<< standard_deviation << endl;
	}
	return 0;
}