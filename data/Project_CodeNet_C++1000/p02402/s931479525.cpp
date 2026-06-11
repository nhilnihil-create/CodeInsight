#include <iostream>

using namespace std;

int main() {
	long n;
	cin >> n;
	long a[150000];
	for (long i = 0; i < n; i++) {
		cin >> a[i];
	}
	int big = a[0], small = a[0];
	for (long k = 0; k < n; k++) {
		if (a[k] > big) {
			big = a[k];
		}
		else if (a[k] < small) {
			small = a[k];
		}
	}
	long s;
	for (long k = 0; k < n; k++) {
		s += a[k];
	}
	cout << small <<" "<< big <<" "<<s<< endl;
}