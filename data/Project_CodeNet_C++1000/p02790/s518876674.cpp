#include "bits/stdc++.h"
using namespace std;

int main() {
	string A,B;
	cin >> A >> B;
	if (A[0] > B[0]) {
		for (int n = 0 ;n<A[0]-'0';++n) {
			cout << B;
		}
	}
	else {
		for (int n = 0; n < B[0]-'0'; ++n) {
			cout << A;
		}
	}
	return 0;
}