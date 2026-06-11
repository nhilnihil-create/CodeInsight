#include "bits/stdc++.h"

using namespace std;



int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int n, m;
	if (C % B == 0) {
		n = C / B;
	}
	else {
		n = C / B + 1;
	}
	if (A % D == 0) {
		m = A/ D;
	}
	else {
		m = A / D + 1;
	}
	if (n <= m) {
		cout << "Yes"<< endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}