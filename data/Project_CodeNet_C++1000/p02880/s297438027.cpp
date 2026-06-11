#include<iostream>
using namespace std;

int main() {
	int n; cin >> n;

	bool ok = false;
	for (int num1 = 1; num1 < 10; num1++) {
		for (int num2 = 1; num2 < 10; num2++) {
			if (num1 * num2 == n)ok = true;
		}
	}
	cout << (ok ? "Yes" : "No") << endl;

	return 0;
}