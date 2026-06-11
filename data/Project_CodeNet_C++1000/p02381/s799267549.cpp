#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
	int n, s[1000], sum;
	double a, avg, ssum;

	while (1) {
		ssum = 0;
		sum = 0;

		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < n; i++) {
			cin >> s[i];

			sum += s[i];
		}

		avg = 1.0*sum / n;

		for (int i = 0; i < n; i++) {
			ssum += pow(s[i] - avg, 2);
		}

		a = ssum / n;

		cout << sqrt(a) << endl;
	}
	
	return 0;
}