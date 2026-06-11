#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	bool bret = true;
	for (int n = 0;n<3; ++n) {
		if (S[n] ==S[n+1]) {
			bret = false;
		}
	}
	if (bret) {
		cout << "Good" << endl;
	}
	else {
		cout << "Bad" << endl;
	}
	
	return 0;
}