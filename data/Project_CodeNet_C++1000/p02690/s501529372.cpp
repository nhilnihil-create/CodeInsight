#include "bits/stdc++.h"
using namespace std;

int main() {
	long long int x;
	cin >> x;

	for (int i = 119; i >= -118; i--) {
		for (int j = i - 1; j >= -119; j--) {
			if (pow(i, 5) - pow(j, 5) == x) {
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
}