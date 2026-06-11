#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	int n, i;
	double s[1000], sum, var, sd, m;
	while (1) {
		cin >> n;
		if (n == 0)break;
		sum = 0;
		for (i = 0; i < n; i++) {
			cin >> s[i];
			sum += s[i];
		}
		m = sum / n;
		var = 0;
		for (i = 0; i < n; i++) {
			var += (s[i] - m) * (s[i] - m);
		}
		var /= n;
		sd = sqrt(var);
		cout << setprecision(10) << sd << endl;
	}
	return 0;
}