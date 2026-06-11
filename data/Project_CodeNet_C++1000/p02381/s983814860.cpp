#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	unsigned int n;
	while (true) {
		double ave = 0.0;
		double a = 0.0;
		vector<double> s;

		cin >> n;
		if (n == 0) break;

		s.resize(n);
		for (unsigned int i = 0; i < n; ++i) {
			cin >> s[i];
			ave += s[i];
		}
		ave /= n;
		for (unsigned int i = 0; i < n; ++i) {
			a += pow(fabs(s[i]-ave), 2);
		}

		cout << setprecision(10) << sqrt(a/n) << endl;
	}
	return 0;
}

