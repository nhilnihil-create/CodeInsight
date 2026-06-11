#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n = 0;
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	bool tf = true;

	for (int j = 0; j < n; j++) {
		if (num[j] % 2 == 0) {
			if (num[j] % 3 != 0 && num[j] % 5 != 0) {
				tf = false;
				break;
			}
		}
	}

	if (tf) {
		cout << "APPROVED" << endl;
	}

	else {
		cout << "DENIED" << endl;
	}
}