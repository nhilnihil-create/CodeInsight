#include "bits/stdc++.h"
using namespace std;

int main() {
	int A,B,C;
	cin >> A>>B>>C;
	if (A ==B&&A==C&&B==C) {
		cout << "No" << endl;
		return 0;
	}
	if (0 == (A-B)*(A-C)*(B-C)) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No"<<endl;
	return 0;
}