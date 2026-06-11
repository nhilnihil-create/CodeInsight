#include <iostream>
#include <math.h>

using namespace std;

int main(void) {

	while (1) {
		int n;
		double ave = 0;
		double var = 0;
		cin >> n;
		int *m = new int[n];

		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			cin >> m[i];
			ave += m[i];
		}
		ave /= n;
		for (int i = 0; i < n; i++) {
			var += pow(m[i] - ave, 2) / n;
		}
		var = sqrt(var);
		cout << var << endl;

		delete[] m;
	}
	
	return 0;
}