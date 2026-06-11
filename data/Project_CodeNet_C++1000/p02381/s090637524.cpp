#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

int main()
{
	int n;

	while (true) {
		cin >> n;
		if (n == 0) break;

		double* s = new double[n];
		double m = 0.0;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			m += temp;
			s[i] = temp;
		}
		m = m / static_cast<double>(n);

		double a = 0.0;
		for (int i = 0; i < n; i++) {
			a += (s[i] - m)*(s[i] - m);
		}

		a = a / static_cast<double>(n);
		cout << fixed << setprecision(8) << sqrt(a) << "\n";

		delete[] s;
	}

	return 0;
}