#include "bits/stdc++.h"

using namespace std;

int main() {

	int N;
	cin >> N;

	int sum = 0;

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if ((i * j) == N) {
				cout << "Yes" << endl;
				sum++;
				break;
			}
		}
		if (sum > 0)
			break;
	}
	
	if (sum == 0)
		cout << "No" << endl;
}