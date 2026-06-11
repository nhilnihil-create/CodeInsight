#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <string.h>
using namespace std;

int main() {
	int			N;
	unsigned long long	A, sum = 1;
	long long	l[100000];

	cin >> N;

	for (int ii = 0; ii < N; ii++) {
		cin >> A;
		if (A == 0) {
			cout << 0 << endl;
			return 0;
		}
		l[ii] = A;
	}

	for (int ii = 0; ii < N; ii++) {
		if (sum * l[ii] == 0 || sum * l[ii] > 1000000000000000000) {
			cout << -1 << endl;
			return 0;
		}
		else {
			if (sum * l[ii] / l[ii] == sum) {
				sum = sum * l[ii];
			}
			else {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << sum << endl;
	return 0;
}