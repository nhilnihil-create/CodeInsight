#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	long long kane = 1000;
	long long kabu = 0;
	bool kai = true;
	for (int i = 0;i < n;i++) {
		if (i == n - 1) {
			kane += kabu * a[i];
			kabu = 0;
		}
		else {
			if (kai) {
				if (a[i] < a[i + 1]) {
					kabu += (kane / a[i]);
					kane -= (kane / a[i]) * a[i];
					kai = false;
				}
			}
			else {
				if (a[i] > a[i + 1]) {
					kane += kabu * a[i];
					kabu = 0;
					kai = true;
				}
			}
		}
	}
	cout << kane << endl;
}