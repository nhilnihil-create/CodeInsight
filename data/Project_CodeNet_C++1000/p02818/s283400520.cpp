#include "bits/stdc++.h"
using namespace std;

int main() {
	long long  A,B,K;
	cin >> A >> B >>K;
	if (A+B<=K) {
		cout << "0 0" << endl;
	}
	else {
		if (A <= K) {
			K = K - A; 
			A = 0;
			B = B - K;
		}
		else {
			A = A - K;
		}
		cout << A <<" "<< B<<endl;
	}
	return 0;
}