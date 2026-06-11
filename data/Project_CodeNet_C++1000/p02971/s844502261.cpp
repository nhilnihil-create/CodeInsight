#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	for (int i = 0;i < n;i++) {
		if (a[i] == b[n - 1]) {
			cout << b[n - 2] << endl;
		}
		else {
			cout << b[n - 1] << endl;
		}
	}
}