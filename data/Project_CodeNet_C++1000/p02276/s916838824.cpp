#include<iostream>
using namespace std;

int x[1000000], n;

int func(int t, int r) {
	int p, a, b, j;
	p = x[r];
	j = t - 1;
	for (int i = t; i < r; i++) {
		if (x[i] <= p) {
			j = j + 1;
			a = x[i];
			b = x[j];
			x[i] = b;
			x[j] = a;
		}
	}
	a = x[j + 1];
	b = x[r];
	x[j + 1] = b;
	x[r] = a;
	return j + 1;
}

int main() {
	int c;
	cin >> n;
	for (int k = 0; k < n; k++) {
		cin >> x[k];
	}
	c = func(0, n - 1);
	for (int k = 0; k < n; k++) {
		if (k) {
			cout << ' ';
		}
		if (k == c) {
			cout << '[';
		}
		cout << x[k];
		if (k == c) {
			cout << ']';
		}
	}
	cout << endl;
	return 0;
}