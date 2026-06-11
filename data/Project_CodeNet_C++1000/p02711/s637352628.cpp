#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846264338327950L

int main() {
	string S;
	cin >> S;

	for ( int ii = 0; ii < S.length(); ii++ ) {
		if ( S[ii] == '7' ) {
			cout << "Yes" << endl;
			return 0;
		}
	} 
	cout << "No" << endl;
	return 0;
}