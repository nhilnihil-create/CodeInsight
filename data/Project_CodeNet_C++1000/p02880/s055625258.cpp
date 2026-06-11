#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >>N;
	set<int>S;
	for (int n = 1;n<=9;++n) {
		for (int m = 1;m<=9;++m) {
			S.insert(n*m);
		}
	}
	set<int>::iterator it = S.find(N);
	if (it != S.end()) {
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}