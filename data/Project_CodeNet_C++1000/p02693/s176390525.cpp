#include<iostream>
using namespace std;


int main() {
	int want = 0, hi = 0, low = 0;
	cin >> want >> low >> hi;

	bool ans = false;

	while (low <= hi) {
		if (low % want == 0) {
			ans = true;
			break;
		}

		low++;
	}

	if (ans) {
		cout << "OK" << endl;
	}

	else {
		cout << "NG" << endl;
	}
}