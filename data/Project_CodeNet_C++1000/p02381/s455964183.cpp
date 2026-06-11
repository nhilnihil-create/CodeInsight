#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n, s;
	double ave, sdev, sum1, sum2;
	while (1) {
		sum1 = sum2 = 0;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> s;
			sum1 += s;
			sum2 += s*s;
		}
		ave = sum1 / n;
		sdev = sqrt(sum2 / n - ave*ave);
		cout << fixed;
		cout << setprecision(6) << sdev << endl;
	}
	return 0;
}
