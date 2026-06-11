#include "bits/stdc++.h"

using namespace std;

int main() {
	string T;
	cin >> T;
	for (int n = 0;n < T.length();++n) {
		if ('?' == T[n]) {
			T[n] = 'D';
		}
	}
	cout << T  << endl;


	return 0;
}