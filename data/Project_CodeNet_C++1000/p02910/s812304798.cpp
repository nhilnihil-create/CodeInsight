#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	for (int n = 0;n<S.size(); ++n) {
		if (0 ==n%2) {
			if ('L' == S[n]) {
				cout << "No"<<endl;
				return 0;
			}
		}
		else {
			if ('R' == S[n]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}