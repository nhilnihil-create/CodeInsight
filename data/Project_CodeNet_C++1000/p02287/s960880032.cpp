#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n+1];
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++) {
		cout << "node " << i << ": key = " << a[i]<<", ";
		if (i != 1) {
			cout << "parent key = " << a[i / 2]<<", ";
		}
		if (2 * i <= n) {
			cout << "left key = " << a[2 * i] << ", ";
		}
		if (2 * i + 1 <= n) {
			cout << "right key = " << a[2 * i + 1] << ", ";
		}
		cout << endl;
	}
}
