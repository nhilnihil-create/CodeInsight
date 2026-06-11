#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <string.h>
#include <iomanip>
using namespace std;

#define PI 3.14159265358979323846264338327950L

int main() {
	string S, T;

	cin >> S >> T;

	if (!(S.length() >= 1 && S.length() <= 10) ||
		T.length() != S.length() + 1) {
		goto NO;
	}
	for (int ii = 0; ii < T.length(); ii++) {
		if (!(T[ii] >= 'a' && T[ii] <= 'z')) {
			goto NO;
		}
		if (ii == T.length() - 1) {
			continue;
		}
		if (T[ii] != S[ii]) {
			goto NO;
		}
	}

	cout << "Yes" << endl;
	return 0;
	
NO:	cout << "No" << endl;
	return 0;
}