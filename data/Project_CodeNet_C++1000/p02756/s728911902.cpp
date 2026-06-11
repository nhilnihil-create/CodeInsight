#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	string A;
	string Z;
	cin >> S;
	int Q;
	cin >> Q;
	int nRev = 1;
	for (int n = 0;n<Q;++n) {
		int t;
		cin >> t;
		if (1==t) {
			//反転
			nRev *= -1;
		}
		else {
			int f;
			cin >> f;
			string s;
			cin >> s;
			if (1==f) {
				if (1 == nRev) {
					A += s;
				}
				else {
					Z += s;
				}
			}
			else {
				if (1 == nRev) {
					Z += s;
				}
				else {
					A += s;
				}
			}
		}
	}
	string ansstr;
	reverse(A.begin(), A.end());
	ansstr += A;
	ansstr += S;
	ansstr += Z;
	if (-1 == nRev) {
		reverse(ansstr.begin(), ansstr.end());
	}
	cout << ansstr<< endl;
	return 0;
}