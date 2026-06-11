#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	long n = 0, g = 0, v = 0, cnt = 0, m = 0;

	cin >> n;

	vector <long> a(n);

	for (long i = 0; i < n; i++)
		cin >> a[i];

	cnt = 0;
	if (n < 3)
		m = 1;
	else
		m = (int)(log(n) / log(3));

	vector <long> G(m);		

	for (long k = 0; k < m; k++) {
		G[k] = ((long)pow(3, m - k) - 1) / 2;
		g = G[k];

		for (long i = g; i < n; i++) {

			long j = 0;

			v = a[i];
			j = i - g;

			while (j >= 0 && a[j] > v) {
				a[j + g] = a[j];
				j = j - g;
				cnt++;
			}

			a[j + g] = v;
		}
	}

	cout << m << endl;

	for (long i = 0; i < m - 1; i++)
		cout << G[i] << " ";
	cout << G[m - 1] << endl;

	cout << cnt << endl;

	for (long i = 0; i < n; i++)
		cout << a[i] << endl;	

	return 0;
}