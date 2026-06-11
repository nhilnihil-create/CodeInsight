#include <iostream>
using namespace std;

int main()
{
	int n, s = 0, rmin, imin;
	int a[100][100];
	int b[100];

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
			b[i] = -1;

	b[0] = 0;
	int ct = 0;

	while (ct < n - 1) {
		imin = 0;
		rmin = 10000;
		for (int j = 0; j < n; j++) {
			if (b[j] > -1) {
				for (int i = 1; i < n; i++) {
					if (a[j][i] > -1 && b[i] < 0 && rmin > a[j][i]) {
						rmin = a[j][i];
						imin = i;
					}
				}
			}
		}
		b[imin] = rmin;
		ct++;
	}

	for (int i = 0; i < n; i++)
		s += b[i];

	cout << s << endl;

	return 0;
}
