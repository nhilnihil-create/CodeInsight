#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;
	for (int n = 0;n<N; ++n) {
		int num;
		cin >> num;
		if (num != n+1) {
			count++;
		}
	}
	if (count <= 2) {
		cout << "YES"<< endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}