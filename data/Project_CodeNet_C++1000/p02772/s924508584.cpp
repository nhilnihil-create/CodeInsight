#include "bits/stdc++.h"

using namespace std;

int main() {
	int N;
	cin >> N;
	bool b = true;
	for (int n = 0;n<N;++n) {
		int m;
		cin >> m;
		if (0 == m %2) {
			if (0 != m%3 && 0 != m%5) {
				b = false;
			}
		}
	}
	if (b) {
		cout << "APPROVED" << endl;
	}
	else{
		cout << "DENIED" << endl;
	}
	return 0;
}