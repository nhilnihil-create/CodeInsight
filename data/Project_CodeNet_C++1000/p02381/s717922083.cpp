#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{

	int n, s[1000] = {};
	double a, m, t;

	while (1) {
		cin >> n;
		if (n == 0) break;

		m = t = 0;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			m += s[i];
		}
		m = m / n;
		for (int i = 0; i < n; i++) {
			t += (s[i] - m) * (s[i] - m);
		}
		a = sqrt(t / n);
		cout << fixed << a << endl;
	}

	return 0;
}