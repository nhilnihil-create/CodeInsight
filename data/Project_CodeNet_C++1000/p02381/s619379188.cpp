#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int n = 0;

	cin >> n;

	while (n > 0) {

		int a[1001] = { 0 }, t1 = 0, t2 = 0;

		double m = 0, s = 0;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			t1 += a[i];
			t2 += a[i] * a[i];
		}

		m = (double) t1 / (double) n;
		s = sqrt((double) t2 / (double) n - m * m);

		cout << setprecision(10) << setiosflags(ios::showpoint) << s << endl;

		cin >> n;
	}
    return 0;
}